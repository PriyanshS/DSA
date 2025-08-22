#include <iostream>
#include <string>
using namespace std;

char myStack[100];
int top = -1;

void push(char ch)
{
    myStack[++top] = ch;
}

char pop()
{
    return myStack[top--];
}

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    if (open == '{' && close == '}')
        return true;
    if (open == '[' && close == ']')
        return true;
    return false;
}

int main()
{
    string Exp;
    cout << "Enter an expression: ";
    cin >> Exp;

    bool balanced = true;

    for (int i = 0; Exp[i] != '\0'; i++)
    {
        char ch = Exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                balanced = false;
                break;
            }

            char open = pop();
            if (!isMatching(open, ch))
            {
                balanced = false;
                break;
            }
        }
    }

    if (top != -1)
        balanced = false;

    if (balanced)
        cout << "The expression is balanced." << endl;
    else
        cout << "The expression is NOT balanced." << endl;

    return 0;
}