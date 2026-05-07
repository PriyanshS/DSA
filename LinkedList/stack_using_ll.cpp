#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *top = nullptr;

bool isEmpty()
{
    return top == nullptr;
}

void Push(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
void Pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow! Cannot pop.";
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

void Display()
{
    if (isEmpty())
    {
        cout << "Stack is empty.";
        return;
    }
    cout << "Stack elements: TOP -> ";
    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int main()
{
    int choice, value;
    while (true)
    {
        cout << "Choose an operation to perform: \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            Push(value);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Close the program" << endl;
            return 0;
        }
        }
    return 0;
}