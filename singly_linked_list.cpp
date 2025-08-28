#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

bool isEmpty(Node *head)
{
    return head == nullptr;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position)
{
    if (position < 1)
    {
        cout << "Position should be >= 1\n";
        return;
    }

    // If inserting at position 1, insert at beginning
    if (position == 1)
    {
        insertAtBeginning(head, data);
        cout << "Element inserted at position " << position << " successfully!\n";
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Element inserted at position " << position << " successfully!\n";
}

void deleteAtBeginning(Node **head)
{
    if (isEmpty(*head))
    {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    cout << "Deleted element: " << temp->data << endl;
    delete temp;
}

void deleteAtEnd(Node **head)
{
    if (isEmpty(*head))
    {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    // If only one node exists
    if ((*head)->next == nullptr)
    {
        cout << "Deleted element: " << (*head)->data << endl;
        delete *head;
        *head = nullptr;
        return;
    }

    // Traverse to second last node
    Node *temp = *head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    cout << "Deleted element: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node at specific position
void deleteAtPosition(Node **head, int position)
{
    if (isEmpty(*head))
    {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    if (position < 1)
    {
        cout << "Position should be >= 1\n";
        return;
    }

    // If deleting first node
    if (position == 1)
    {
        deleteAtBeginning(head);
        return;
    }

    Node *temp = *head;

    // Traverse to position-1
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    // Check if position is valid
    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Position out of range!\n";
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted element at position " << position << ": " << nodeToDelete->data << endl;
    delete nodeToDelete;
}

// Function to delete a node by value
void deleteByValue(Node **head, int value)
{
    if (isEmpty(*head))
    {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    // If first node contains the value
    if ((*head)->data == value)
    {
        deleteAtBeginning(head);
        return;
    }

    Node *temp = *head;

    // Search for the node with given value
    while (temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }

    // If value not found
    if (temp->next == nullptr)
    {
        cout << "Value " << value << " not found in the list!\n";
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted element with value " << value << endl;
    delete nodeToDelete;
}

void displayList(Node *head)
{
    if (isEmpty(head))
    {
        cout << "List is empty!\n";
        return;
    }

    cout << "Linked List: ";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Function to count total nodes
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search for an element
void searchElement(Node *head, int value)
{
    Node *temp = head;
    int position = 1;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "Element " << value << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Element " << value << " not found in the list!\n";
}

// Function to reverse the linked list
void reverseList(Node **head)
{
    if (*head == nullptr || (*head)->next == nullptr)
    {
        return;
    }

    Node *prev = nullptr;
    Node *current = *head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to check if the list is a palindrome
bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    // 1. Find the middle of the list
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half of the list
    Node *secondHalf = slow->next;
    Node *prev = nullptr;
    Node *current = secondHalf;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    secondHalf = prev; // New head of the reversed second half

    // 3. Compare the first half with the reversed second half
    Node *firstHalf = head;
    Node *p1 = firstHalf;
    Node *p2 = secondHalf;
    bool result = true;
    while (p2 != nullptr)
    {
        if (p1->data != p2->data)
        {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. Restore the original list (reverse the second half back)
    current = secondHalf;
    prev = nullptr;
    next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    slow->next = prev;

    return result;
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(Node *head)
{
    // The list is empty or has only one node
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            Node *nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        else
        {
            current = current->next;
        }
    }
}

// Function to free all nodes and clean up memory
void freeList(Node **head)
{
    Node *current = *head;
    Node *next;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    *head = nullptr;
}

int main()
{
    Node *head = nullptr;
    int choice, data, position;

    cout << "\n SINGLY LINKED LIST \n";

    while (true)
    {
        cout << "\n____MENU___\n";
        cout << "1.  Insert at Beginning\n";
        cout << "2.  Insert at End\n";
        cout << "3.  Insert at Position\n";
        cout << "4.  Delete at Beginning\n";
        cout << "5.  Delete at End\n";
        cout << "6.  Delete at Position\n";
        cout << "7.  Delete by Value\n";
        cout << "8.  Display List\n";
        cout << "9.  Count Nodes\n";
        cout << "10. Search Element\n";
        cout << "11. Reverse List\n";
        cout << "12. Clear List\n";
        cout << "13. Remove Duplicates (from sorted list)\n";
        cout << "14. Check for Palindrome\n";
        cout << "15. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at beginning: ";
            cin >> data;
            insertAtBeginning(&head, data);
            cout << "Element inserted successfully!\n";
            break;

        case 2:
            cout << "Enter data to insert at end: ";
            cin >> data;
            insertAtEnd(&head, data);
            cout << "Element inserted successfully!\n";
            break;

        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position (1-based): ";
            cin >> position;
            insertAtPosition(&head, data, position);
            break;

        case 4:
            deleteAtBeginning(&head);
            break;

        case 5:
            deleteAtEnd(&head);
            break;

        case 6:
            cout << "Enter position to delete (1-based): ";
            cin >> position;
            deleteAtPosition(&head, position);
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> data;
            deleteByValue(&head, data);
            break;

        case 8:
            displayList(head);
            break;

        case 9:
            cout << "Total nodes in the list: " << countNodes(head) << endl;
            break;

        case 10:
            cout << "Enter element to search: ";
            cin >> data;
            searchElement(head, data);
            break;

        case 11:
            reverseList(&head);
            cout << "List reversed successfully!\n";
            break;

        case 12:
            freeList(&head);
            cout << "List cleared successfully!\n";
            break;

        case 13:
            removeDuplicates(head);
            cout << "Duplicates removed from the list.\n";
            displayList(head);
            break;

        case 14:
            if (isPalindrome(head))
            {
                cout << "The list is a palindrome.\n";
            }
            else
            {
                cout << "The list is not a palindrome.\n";
            }
            break;

        case 15:
            freeList(&head);
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }

    return 0;
}