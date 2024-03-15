#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

// implement a stack-based algorithm to reverse a string.

void reverseString(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    for (int i = 0; i < s.length(); i++)
    {
        s[i] = st.top();
        st.pop();
    }
}

int main()
{
    string s = "helloThere";

    reverseString(s);

    cout << "reversed : " << s << endl;
    return 0;
}