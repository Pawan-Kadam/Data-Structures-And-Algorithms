#include <iostream>
using namespace std;

// Stack code starts here
class Stack
{
private:
    int top;
    int size;
    char *S;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        S = new char[size];
    }

    bool isEmpty();
    bool isFull();
    void push(char a);
    char pop();
};

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    return false;
}

void Stack::push(char a)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        S[top] = a;
    }
}

char Stack::pop()
{
    char a;
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        a = S[top];
        top--;
    }
    return a;
}

// Stack code ends here

bool checkParenthesisAdv(string s, int l)
{
    Stack st(l);
    for (int i = 0; i < l; ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.isEmpty())
            {
                return false;
            }
            else
            {
                char x = st.pop();

                if (s[i] == ')')
                {
                    if (x == '[' || x == '{')
                    {
                        return false;
                    }
                }
                else if (s[i] == ']')
                {
                    if (x == '(' || x == '{')
                    {
                        return false;
                    }
                }
                else
                {
                    if (x == '(' || x == '[')
                    {
                        return false;
                    }
                }
            }
        }
    }
    if (st.isEmpty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cout << "Enter the Expression : ";
    cin >> s;

    int len = s.length();

    if (checkParenthesisAdv(s, len))
    {
        cout << "Parenthesis are equal" << endl;
    }
    else
    {
        cout << "Parenthesis are not equal" << endl;
    }

    return 0;
}
