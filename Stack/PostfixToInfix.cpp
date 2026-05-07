#include <iostream>
#include <string>
using namespace std;

int top = -1;
int stack[100];
string output; // Not used for evaluation, kept for compatibility

bool isEmpty()
{
    return top == -1;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void push(int c)
{
    if (top < 99)
    {
        top = top + 1;  // Increment top first
        stack[top] = c; // Then assign value
    }
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    int value = stack[top]; // Get the value first
    top--;                  // Then decrement top
    return value;
}

int peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    return 0;
}

bool isNum(char x)
{
    return x >= '0' && x <= '9';
}

void PostfixEvaluate(char x)
{
    if (isNum(x))
    {
        push(x - '0'); // Convert char digit to int (e.g., '2' -> 2)
    }
    else if (isOperator(x))
    {
        if (top < 1) // Need at least 2 elements for binary operation
        {
            cout << "Error: Insufficient operands for operator " << x << endl;
            return;
        }
        int b = pop(); // Second operand
        int a = pop(); // First operand
        switch (x)
        {
        case '+':
            push(a + b);
            break;
        case '-':
            push(a - b);
            break;
        case '*':
            push(a * b);
            break;
        case '/':
            if (b == 0)
            {
                cout << "Error: Division by zero" << endl;
                return;
            }
            push(a / b);
            break;
        }
    }
}

int main()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    int n = postfix.length();

    // Process each character of the postfix expression
    for (int j = 0; j < n; j++)
    {
        PostfixEvaluate(postfix[j]);
    }

    if (!isEmpty())
    {
        cout << "The evaluated expression is: " << stack[top] << endl;
    }
    else
    {
        cout << "Error: Invalid expression" << endl;
    }

    return 0;
}