#include <iostream>

using namespace std;

// Node structure for the Binary Search Tree
struct Node
{
    int key;
    Node *left, *right;

    Node(int item)
    {
        key = item;
        left = right = nullptr;
    }
};

// BST class
class BST
{
public:
    Node *root;

    BST()
    {
        root = nullptr;
    }

    // Function to insert a new node with a given key
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // Function to search a given key in a BST
    Node *search(Node *node, int key)
    {
        if (node == nullptr || node->key == key)
        {
            return node;
        }
        if (key < node->key)
        {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    // Function to find the node with the minimum key value found in that tree
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    // Function to delete the node with the given key
    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Node with only one child or no child
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    // Inorder traversal
    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    // Preorder traversal
    void preorder(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Postorder traversal
    void postorder(Node *root)
    {
        if (root != nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }
};

void showMenu()
{
    cout << " Binary Search Tree Operations \n";
    cout << "1. Insert a node\n";
    cout << "2. Delete a node\n";
    cout << "3. Search for a node\n";
    cout << "4. Display Inorder Traversal\n";
    cout << "5. Display Preorder Traversal\n";
    cout << "6. Display Postorder Traversal\n";
    cout << "7. Exit\n";
    cout << "\n";
    cout << "Enter your choice: ";
}

int main()
{
    BST bst;
    int choice, key;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            bst.root = bst.insert(bst.root, key);
            cout << "Key " << key << " inserted.\n";
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            if (bst.search(bst.root, key))
            {
                bst.root = bst.deleteNode(bst.root, key);
                cout << "Key " << key << " deleted.\n";
            }
            else
            {
                cout << "Key " << key << " not found in the tree.\n";
            }
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            if (bst.search(bst.root, key) != nullptr)
            {
                cout << "Key " << key << " found in the tree.\n";
            }
            else
            {
                cout << "Key " << key << " not found in the tree.\n";
            }
            break;
        case 4:
            cout << "Inorder traversal: ";
            bst.inorder(bst.root);
            cout << endl;
            break;
        case 5:
            cout << "Preorder traversal: ";
            bst.preorder(bst.root);
            cout << endl;
            break;
        case 6:
            cout << "Postorder traversal: ";
            bst.postorder(bst.root);
            cout << endl;
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}