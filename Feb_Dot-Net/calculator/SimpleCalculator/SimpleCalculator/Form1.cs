using SimpleCalculator.Calculate;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SimpleCalculator
{
    public partial class Calculator : Form
    {
        string equation = "";
        bool dotCountIs1 = false;
        bool isLastCharIsOperator = false;
        bool isRootIsFirst = false;
        private DateTime lastKeyPressTime = DateTime.MinValue;


        public Calculator()
        {
            InitializeComponent();
            this.KeyPreview = true;
            this.AcceptButton = null;
        }

        private void BindTextBox()
        {
            displayTxt.Text = equation;
        }

        private void ModifyEquation(string ch)
        {

            if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^")
            {
                if (!isLastCharIsOperator)
                {
                    equation += ch;
                    isLastCharIsOperator = true;
                    dotCountIs1 = false;
                    isRootIsFirst = false;
                }
            }
            else if (ch == "√")
            {
                if (!isRootIsFirst)
                {
                    equation += ch;
                    isRootIsFirst = false;
                    dotCountIs1 = true;
                }
            }
            else if (ch == ".")
            {
                if (!dotCountIs1)
                {
                    equation += ch;
                    dotCountIs1 = true;
                }
            }
            else
            {
                equation += ch;
                isLastCharIsOperator = false;
            }
            BindTextBox();

        }


        private double CalculateResult(string eq)
        {
            return Calculate.Calculate.CalculateEquation(eq);
        }

        private void AllBtn_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            string ch = btn.Text;
            ModifyEquation(ch);
        }


        private void btnBack_Click(object sender, EventArgs e)
        {
            if (equation != "")
            {
                equation = equation.Substring(0, equation.Length - 1);
                BindTextBox();
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            equation = "";
        }

        private void btnSquare_Click(object sender, EventArgs e)
        {
            ModifyEquation("^");
        }

        private void btnSqrt_Click(object sender, EventArgs e)
        {
            ModifyEquation("√");
        }

        private void btnEqual_Click(object sender, EventArgs e)
        {
            GetResults();
        }

        private void GetResults()
        {
            try
            {
                if (equation[0] == '√')
                {
                    double res = Math.Sqrt(Convert.ToDouble(equation.Substring(1)));
                    equation = Convert.ToString(res);
                    BindTextBox();
                }
                else
                {
                    double ans = CalculateResult(equation);
                    equation = Convert.ToString(ans);
                    BindTextBox();
                    equation = "";
                }
            }
            catch (ArgumentException ex)
            {
                displayTxt.Text = ex.Message;
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {

            TimeSpan elapsed = DateTime.Now - lastKeyPressTime;
            if (elapsed.TotalMilliseconds < SystemInformation.KeyboardSpeed)
            {
                return;
            }

            lastKeyPressTime = DateTime.Now;

            if (e.Shift && e.KeyCode == Keys.D6)
            {
                ModifyEquation("^");
            }
            else if (e.Control && e.KeyCode == Keys.Enter)
            {
                GetResults();
            }
            else
            {


                switch (e.KeyCode)
                {
                    case Keys.D0:
                    case Keys.NumPad0:
                        ModifyEquation("0");
                        break;
                    case Keys.D1:
                    case Keys.NumPad1:
                        ModifyEquation("1");
                        break;
                    case Keys.D2:
                    case Keys.NumPad2:
                        ModifyEquation("2");
                        break;
                    case Keys.D3:
                    case Keys.NumPad3:
                        ModifyEquation("3");
                        break;
                    case Keys.D4:
                    case Keys.NumPad4:
                        ModifyEquation("4");
                        break;
                    case Keys.D5:
                    case Keys.NumPad5:
                        ModifyEquation("5");
                        break;
                    case Keys.D6:
                    case Keys.NumPad6:
                        ModifyEquation("6");
                        break;
                    case Keys.D7:
                    case Keys.NumPad7:
                        ModifyEquation("7");
                        break;
                    case Keys.D8:
                    case Keys.NumPad8:
                        ModifyEquation("8");
                        break;
                    case Keys.D9:
                    case Keys.NumPad9:
                        ModifyEquation("9");
                        break;
                    case Keys.Decimal:
                        ModifyEquation(".");
                        break;
                    case Keys.Add:
                        ModifyEquation("+");
                        break;
                    case Keys.Subtract:
                        ModifyEquation("-");
                        break;
                    case Keys.Multiply:
                        ModifyEquation("*");
                        break;
                    case Keys.Divide:
                        ModifyEquation("/");
                        break;
                    case Keys.OemOpenBrackets:
                        ModifyEquation("^");
                        break;
                    case Keys.Enter:
                        GetResults();
                        break;
                    case Keys.A:
                        GetResults();
                        break;
                    case Keys.Back:
                        if (equation != "")
                        {
                            equation = equation.Substring(0, equation.Length - 1);
                            BindTextBox();
                        }
                        break;

                    case Keys.C:
                        equation = "";
                        BindTextBox();
                        break;
                    default:
                        //MessageBox.Show("Invalid Key");
                        break;
                }
            }


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.KeyDown += new KeyEventHandler(this.Form1_KeyDown);
        }
    }
}
