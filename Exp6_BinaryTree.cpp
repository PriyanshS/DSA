#include <iostream>

using namespace std;

// Node structure for the Binary Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Node structure for the Queue
class QNode
{
public:
    Node *data;
    QNode *next;

    QNode(Node *node)
    {
        data = node;
        next = nullptr;
    }
};

// Queue class for level-order creation
class Queue
{
    QNode *front, *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(Node *node)
    {
        QNode *temp = new QNode(node);
        if (rear == nullptr)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    Node *dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        QNode *temp = front;
        Node *nodeData = temp->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        return nodeData;
    }
};

// BinaryTree class
class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void createTree(int data[], int n)
    {
        if (n == 0)
        {
            return;
        }
        root = new Node(data[0]);
        Queue q;
        q.enqueue(root);

        int i = 1;
        while (i < n)
        {
            Node *current = q.dequeue();

            // Add left child
            if (i < n)
            {
                current->left = new Node(data[i++]);
                q.enqueue(current->left);
            }

            // Add right child
            if (i < n)
            {
                current->right = new Node(data[i++]);
                q.enqueue(current->right);
            }
        }
    }

    void inOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main()
{
    int data[] = {12, 43, 23, 62, 44, 56, 87, 18, 20, 21};
    int n = sizeof(data) / sizeof(data[0]);

    BinaryTree tree;
    tree.createTree(data, n);

    int choice;
    do
    {
        cout << "Choose the operation to perform: \n";
        cout << "1. In-order Traversal\n";
        cout << "2. Pre-order Traversal\n";
        cout << "3. Post-order Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nIn-order Traversal: ";
            tree.inOrder(tree.root);
            cout << endl;
            break;
        case 2:
            cout << "\nPre-order Traversal: ";
            tree.preOrder(tree.root);
            cout << endl;
            break;
        case 3:
            cout << "\nPost-order Traversal: ";
            tree.postOrder(tree.root);
            cout << endl;
            break;
        case 4:
            cout << "Execution finished." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
