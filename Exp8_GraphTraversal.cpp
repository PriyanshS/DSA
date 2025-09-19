#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency matrix

public:
    // Constructor
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V, vector<int>(V, 0));
    }

    // Function to set an edge based on adjacency matrix input
    void setEdge(int u, int v)
    {
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            adj[u][v] = 1;
        }
    }

    // Function to perform Breadth First Search
    void BFS(int startVertex)
    {
        if (startVertex < 0 || startVertex >= V)
        {
            cout << "Invalid start vertex." << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < V; ++i)
            {
                if (adj[v][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Function to perform Depth First Search (Stack-based)
    void DFS(int startVertex)
    {
        if (startVertex < 0 || startVertex >= V)
        {
            cout << "Invalid start vertex." << endl;
            return;
        }
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(startVertex);

        cout << "DFS Traversal: ";
        while (!s.empty())
        {
            int v = s.top();
            s.pop();

            if (!visited[v])
            {
                cout << v << " ";
                visited[v] = true;
            }

            // Push neighbors in reverse order to process them in correct order
            for (int i = V - 1; i >= 0; --i)
            {
                if (adj[v][i] == 1 && !visited[i])
                {
                    s.push(i);
                }
            }
        }
        cout << endl;
    }
};

void printMenu()
{
    cout << " Graph Traversal Menu" << endl;
    cout << "1. Create Graph" << endl;
    cout << "2. Breadth First Search (BFS)" << endl;
    cout << "3. Depth First Search (DFS)" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    int choice;
    Graph *g = nullptr;
    int vertices, startNode;

    do
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (g)
            {
                delete g;
            }
            cout << "Enter the number of vertices: ";
            cin >> vertices;
            g = new Graph(vertices);
            cout << "Enter the adjacency matrix (" << vertices << "x" << vertices << "):\n";
            int edge;
            for (int i = 0; i < vertices; ++i)
            {
                for (int j = 0; j < vertices; ++j)
                {
                    cin >> edge;
                    if (edge == 1)
                    {
                        g->setEdge(i, j);
                    }
                }
            }
            cout << "Graph created." << endl;
            break;
        }
        case 2:
            if (g)
            {
                cout << "Enter the starting node for BFS: ";
                cin >> startNode;
                g->BFS(startNode);
            }
            else
            {
                cout << "Please create a graph first." << endl;
            }
            break;
        case 3:
            if (g)
            {
                cout << "Enter the starting node for DFS: ";
                cin >> startNode;
                g->DFS(startNode);
            }
            else
            {
                cout << "Please create a graph first." << endl;
            }
            break;
        case 4:
            cout << "Exit the loop." << endl;
            if (g)
            {
                delete g;
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
