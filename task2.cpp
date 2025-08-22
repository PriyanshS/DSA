#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX = 100;

class Stack
{
    int data[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int n)
    {
        if (top < MAX - 1)
            data[++top] = n;
    }

    int pop()
    {
        if (top >= 0)
            return data[top--];
        return 0;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int evaluatePostfix(string expr)
{
    Stack s;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            }
        }
    }

    return s.pop();
}

int main()
{
    string postfix;
    cout << "Enter postfix expression (digits only, no spaces): ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
