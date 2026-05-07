#include <iostream>
#include <string>
using namespace std;

int top = -1;
char stack[100];
string output; // To store the postfix expression

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
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
        char c = stack[top--];
        output += c;
    }
    return 0;
}

char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    return 0;
}

bool isEmpty()
{
    return top == -1;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    return 0; // For parentheses or invalid operators
}

bool isAlpha(char x)
{
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

void InfixToPostfix(char x)
{
    if (isAlpha(x))
    {
        output += x; // Append operand to output
    }
    else if (x == '(')
    {
        push(x);
    }
    else if (x == ')')
    {
        // Pop until '(' is found
        while (!isEmpty() && peek() != '(')
        {
            pop(); // Output updated in pop
        }
        if (!isEmpty() && peek() == '(')
        {
            pop(); // Remove '(' from stack, no output update
        }
    }
    else if (isOperator(x))
    {
        // Pop operators with higher or equal precedence
        while (!isEmpty() && peek() != '(' && precedence(x) <= precedence(peek()))
        {
            pop(); // Output updated in pop
        }
        push(x); // Push current operator
    }
}

int main()
{
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    int n = infix.length();

    // Process each character of the infix expression
    for (int i = 0; i < n; i++)
    {
        InfixToPostfix(infix[i]);
    }

    // Pop remaining operators from the stack
    while (!isEmpty())
    {
        if (peek() != '(')
        {
            pop(); // Output updated in pop
        }
        else
        {
            pop(); // Discard any remaining '('
        }
    }

    // Print the postfix expression
    cout << "Postfix expression: " << output << endl;
    return 0;
}