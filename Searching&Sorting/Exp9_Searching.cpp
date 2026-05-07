#include <iostream>
#include <vector>

using namespace std;

// Function to perform Linear Search
int linearSearch(const vector<int> &data, int key)
{
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i] == key)
        {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to perform Binary Search
int binarySearch(const vector<int> &data, int key)
{
    int left = 0;
    int right = data.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (data[mid] == key)
        {
            return mid; // Return the index if key is found
        }
        if (data[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to test the Linear Search algorithm as per Task 1
void testLinearSearch()
{
    cout << "\n--- Testing Linear Search (Task 1) ---" << endl;
    vector<int> data = {23, 87, 45, 12, 67, 34, 90, 56, 78, 11};
    int keys[] = {34, 60};

    cout << "Data Set: ";
    for (int val : data)
    {
        cout << val << " ";
    }
    cout << endl;

    for (int key : keys)
    {
        cout << "Searching for key: " << key << endl;
        int result = linearSearch(data, key);
        if (result != -1)
        {
            cout << "Key " << key << " found at index: " << result << endl;
        }
        else
        {
            cout << "Key " << key << " not found in the data set." << endl;
        }
    }
}

// Function to test the Binary Search algorithm as per Task 2
void testBinarySearch()
{
    cout << "\n--- Testing Binary Search (Task 2) ---" << endl;
    vector<int> data = {12, 23, 34, 45, 56, 67, 78, 87, 90, 99};
    int keys[] = {34, 60};

    cout << "Data Set (sorted): ";
    for (int val : data)
    {
        cout << val << " ";
    }
    cout << endl;

    for (int key : keys)
    {
        cout << "Searching for key: " << key << endl;
        int result = binarySearch(data, key);
        if (result != -1)
        {
            cout << "Key " << key << " found at index: " << result << endl;
        }
        else
        {
            cout << "Key " << key << " not found in the data set." << endl;
        }
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Search Algorithm Menu:" << endl;
        cout << "1. Test Linear Search (Task 1)" << endl;
        cout << "2. Test Binary Search (Task 2)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            testLinearSearch();
            break;
        case 2:
            testBinarySearch();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
