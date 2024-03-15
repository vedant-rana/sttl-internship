using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleCalculator.Calculate
{
    internal class Calculate
    {

        private static int GetPrecedence(char op)
        {
            switch (op)
            {
                case '+': return 1;
                case '-': return 1;
                case '*': return 2;
                case '/': return 2;
                case '^': return 3;
                case '√': return 4;
            }
            return -1;
        }

        public static string ConvertToPostfix(string infix)
        {
            Stack<char> operators = new Stack<char>();
            List<string> postfix = new List<string>();
            string currentNumber = "";

            foreach (char token in infix)
            {
                if (char.IsDigit(token) || token == '.')
                {
                    currentNumber += token;
                }
                else if (!string.IsNullOrEmpty(currentNumber))
                {
                    postfix.Add(currentNumber);
                    currentNumber = "";
                }

                if ("+-*/^√".Contains(token))
                {
                    while (operators.Count > 0 && GetPrecedence(operators.Peek()) >= GetPrecedence(token))
                    {
                        postfix.Add(operators.Pop().ToString());
                    }
                    operators.Push(token);
                }
            }

            if (!string.IsNullOrEmpty(currentNumber))
            {
                postfix.Add(currentNumber);
            }

            while (operators.Count > 0)
            {
                postfix.Add(operators.Pop().ToString());
            }

            return string.Join(" ", postfix);
        }

        public static double Evaluate(string postfix)
        {
            Stack<double> stack = new Stack<double>();
            string number = "";

            foreach (char token in postfix)
            {
                if (char.IsDigit(token) || token == '.')
                {
                    number += token;
                }
                else if (!string.IsNullOrEmpty(number))
                {
                    stack.Push(double.Parse(number, CultureInfo.InvariantCulture));
                    number = "";
                }

                if ("+-*/^√".Contains(token))
                {
                    if (stack.Count < 2)
                    {
                        throw new ArgumentException("Invalid postfix expression");
                    }

                    double b = stack.Pop();
                    double a = stack.Pop();
                    switch (token)
                    {
                        case '+':
                            stack.Push(a + b);
                            break;
                        case '-':
                            stack.Push(a - b);
                            break;
                        case '*':
                            stack.Push(a * b);
                            break;
                        case '/':
                            stack.Push(a / b);
                            break;
                        case '^':
                            stack.Push(Math.Pow(a, b));
                            break;
                        case '√':
                            stack.Push(Math.Sqrt(b));
                            break;
                    }
                }
            }

            if (stack.Count != 1)
            {
                throw new ArgumentException("Invalid expression");
            }

            return stack.Pop();
        }

        public static double CalculateEquation(string equation)
        {
            return Evaluate(ConvertToPostfix(equation));
        }
    }
}
