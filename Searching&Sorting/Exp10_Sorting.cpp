#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to print a vector
void printVector(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

// Merge Sort ---
void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Test Functions ---
void testInsertionSort()
{
    cout << "Task 1: Insertion Sort" << endl;
    vector<int> data = {23, 87, 45, 12, 67, 34, 90, 56, 78, 11};
    cout << "Original Data: ";
    printVector(data);
    insertionSort(data);
    cout << "Sorted Data:   ";
    printVector(data);
}

void testSelectionSort()
{
    cout << "Task 2: Selection Sort" << endl;
    vector<int> data = {12, 23, 34, 45, 56, 67, 78, 87, 90, 99};
    cout << "Original Data: ";
    printVector(data);
    selectionSort(data);
    cout << "Sorted Data:   ";
    printVector(data);
}

void testMergeSort()
{
    cout << "Task 3: Merge Sort" << endl;
    vector<int> data = {13, 62, 34, 45, 16, 76, 38, 57, 9, 29}; // 09 is 9
    cout << "Original Data: ";
    printVector(data);
    mergeSort(data, 0, data.size() - 1);
    cout << "Sorted Data:   ";
    printVector(data);
}

void printMenu()
{
    cout << "||||--- Sorting Algorithms Tasks ---||||" << endl;
    cout << "1.Insertion Sort" << endl;
    cout << "2.Selection Sort" << endl;
    cout << "3.Merge Sort" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    int choice;
    do
    {
        printMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            testInsertionSort();
            break;
        case 2:
            testSelectionSort();
            break;
        case 3:
            testMergeSort();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
