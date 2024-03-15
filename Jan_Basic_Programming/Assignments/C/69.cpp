#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to check for balanced parentheses
bool areParenthesesBalanced(string expression) {
    stack<char> parenStack;

    for (char symbol : expression) {
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            parenStack.push(symbol);
        } else if (symbol == ')' || symbol == ']' || symbol == '}') {
            if (parenStack.empty()) {
                return false;
            }

            char top = parenStack.top();
            parenStack.pop();

            if ((symbol == ')' && top != '(') ||
                (symbol == ']' && top != '[') ||
                (symbol == '}' && top != '{')) {
                return false;
            }
        }
    }

    return parenStack.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "Parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are not balanced." << endl;
    }

    return 0;
}
