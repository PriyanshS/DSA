
// iostream is included for input and output operations,
// such as printing to the console (cout) and reading user input (cin).
#include <iostream>

// vector is used to store the list of data items (e.g., {12, 43, 23, ...})
// that will be used to construct the binary tree. It's a dynamic array.
#include <vector>

// queue is used for the level-order insertion algorithm when creating the tree.
// It helps ensure that nodes are added level by level, from left to right.
#include <queue>

// This line allows us to use names for objects and variables from the standard library
// without having to write 'std::' before each one (e.g., cout instead of std::cout).
using namespace std;

// Node structure for the binary tree as described in the PDF
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create a binary tree from a vector of data using level-order insertion
Node *createBinaryTree(const vector<int> &data)
{
    if (data.empty())
    {
        return nullptr;
    }

    // Create the root node with the first element
    Node *root = new Node(data[0]);

    // Create a queue for level-order insertion and enqueue the root
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (i < data.size())
    {
        Node *current = q.front();
        q.pop();

        // Assign left child
        if (i < data.size())
        {
            current->left = new Node(data[i++]);
            q.push(current->left);
        }

        // Assign right child
        if (i < data.size())
        {
            current->right = new Node(data[i++]);
            q.push(current->right);
        }
    }
    return root;
}

// Algorithm to perform In-order traversal
void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Algorithm to perform Pre-order traversal
void preorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Algorithm to perform Post-order traversal
void postorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void printMenu()
{
    cout << "--- Binary Tree Operations Menu ---";
    cout << "1. Create Binary Tree";
    cout << "2. In-order Traversal";
    cout << "3. Pre-order Traversal";
    cout << "4. Post-order Traversal";
    cout << "5. Exit";
    cout << "Enter your choice: ";
}

int main()
{
    Node *root = nullptr;
    vector<int> data = {12, 43, 23, 62, 44, 56, 87, 18, 20, 21};
    int choice;

    do
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            root = createBinaryTree(data);
            cout << "Binary Tree created successfully with the data: ";
            for (int val : data)
            {
                cout << val << " ";
            }
            cout << endl;
            break;
        case 2:
            if (root)
            {
                cout << "In-order Traversal: ";
                inorderTraversal(root);
                cout << endl;
            }
            else
            {
                cout << "Please create the tree first (Option 1).";
            }
            break;
        case 3:
            if (root)
            {
                cout << "Pre-order Traversal: ";
                preorderTraversal(root);
                cout << endl;
            }
            else
            {
                cout << "Please create the tree first (Option 1).";
            }
            break;
        case 4:
            if (root)
            {
                cout << "Post-order Traversal: ";
                postorderTraversal(root);
                cout << endl;
            }
            else
            {
                cout << "Please create the tree first (Option 1).";
            }
            break;
        case 5:
            cout << "Exiting program.";
            break;
        default:
            cout << "Invalid choice. Please try again.";
        }
    } while (choice != 5);

    // Note: This is a basic cleanup. A full cleanup would require traversing
    // the tree and deleting each node to prevent memory leaks.
    // For this specific program, since it exits right after, this is acceptable.
    delete root;

    return 0;
}
