#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); ++i)
    {
        // Check if scanned char is operand if it is then add it to result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            result += s[i];
        }

        // Check if scanned char is '(' if it is then add it to stack
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // Check if scanned char is ')' if it is then pop from stack until '(' encounters
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top(); // Adds top to result
                st.pop();           // Moves top to next element by removing current element
            }
            st.pop(); // Removes '(' from stack
        }

        // If scanned char is operator
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            // If operator's precedence is higher than the scanned char then push it into stack
            st.push(s[i]);
        }
    }

    // Pop all the remaining elements from the stack and add it to result
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string s;
    s = "a+b*(c^d-e)^(f+g*h)-i";
    // cout << "Enter Infix Expression: ";
    // cin >> s;

    string postfix;
    postfix = infixToPostfix(s);
    cout << "Postfix : " << postfix << endl;

    return 0;
}
