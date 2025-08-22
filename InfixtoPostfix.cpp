#include <iostream>
#include <string>
using namespace std;

int top = -1;
char stack[100];
string output; // To store the postfix expression

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
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
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    return '\0'; // Return null character if stack is empty
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

bool isRightAssociative(char op)
{
    return op == '^'; // Only exponentiation is right associative
}

bool isAlpha(char x)
{
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

bool isDigit(char x)
{
    return x >= '0' && x <= '9';
}

void InfixToPostfix(char x)
{
    if (isAlpha(x) || isDigit(x))
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
            output += pop(); // Add popped operator to output
        }
        if (!isEmpty() && peek() == '(')
        {
            pop(); // Remove '(' from stack, don't add to output
        }
    }
    else if (isOperator(x))
    {
        // Pop operators based on precedence and associativity
        while (!isEmpty() && peek() != '(' &&
               (precedence(x) < precedence(peek()) ||
                (precedence(x) == precedence(peek()) && !isRightAssociative(x))))
        {
            output += pop(); // Add popped operator to output
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

    output = ""; // Initialize output string

    // Process each character of the infix expression
    for (int i = 0; i < n; i++)
    {
        InfixToPostfix(infix[i]);
    }

    // Pop remaining operators from the stack
    while (!isEmpty())
    {
        char op = pop();
        if (op != '(') // Don't add unmatched '(' to output
        {
            output += op;
        }
    }

    // Print the postfix expression
    cout << "Postfix expression: " << output << endl;
    return 0;
}