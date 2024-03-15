#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string>& result, string& expr, const string& num, int target, long long currVal, long long prevNum, int index, char lastOp) {
    if (index == num.size()) {
        if (currVal == target) {
            result.push_back(expr);
        }
        return;
    }

    for (int i = index; i < num.size(); ++i) {
        string currStr = num.substr(index, i - index + 1);
        long long curr = stoll(currStr);

        if (index == 0) {
            expr += currStr;
            backtrack(result, expr, num, target, curr, curr, i + 1, '+');
            expr.pop_back();
        } else {
            // Addition
            expr += '+' + currStr;
            backtrack(result, expr, num, target, currVal + curr, curr, i + 1, '+');
            expr.pop_back();

            // Subtraction
            expr += '-' + currStr;
            backtrack(result, expr, num, target, currVal - curr, -curr, i + 1, '-');
            expr.pop_back();

            // Multiplication
            expr += '*' + currStr;
            if (lastOp == '+') {
                backtrack(result, expr, num, target, currVal - prevNum + prevNum * curr, prevNum * curr, i + 1, '+');
            } else if (lastOp == '-') {
                backtrack(result, expr, num, target, currVal + prevNum - prevNum * curr, -prevNum * curr, i + 1, '-');
            } else {
                backtrack(result, expr, num, target, currVal * curr, prevNum * curr, i + 1, '*');
            }
            expr.pop_back();
        }

        // Handle leading zeros
        if (num[index] == '0') {
            break;
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    string expr;
    backtrack(result, expr, num, target, 0, 0, 0, ' ');
    return result;
}

int main() {
    string num = "123";
    int target = 6;

    vector<string> result = addOperators(num, target);

    cout << "Expressions that evaluate to " << target << ":" << endl;
    for (const string& expr : result) {
        cout << expr << endl;
    }

    return 0;
}
