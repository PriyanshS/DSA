#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int data[] = {3, 41, 52, 26, 38, 57, 9, 49, 25, 19, 23};
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    return 0;
}