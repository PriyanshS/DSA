#include <iostream>
#include <string>
using namespace std;
char stack[100];
int top = -1;

void push(char c)
{
    if (top < 99)
    {
        stack[++top] = c;
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return 'Underflow';
}

char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    return 'Underflow';
}

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(string expr)
{
    top = -1; // Reset stack before use
    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1 || !isMatching(pop(), ch))
            {
                return false;
            }
        }
    }
    return top == -1;
}

int main()
{
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "The expression is balanced." << endl;
    else
        cout << "The expression is NOT balanced." << endl;

    return 0;
}
