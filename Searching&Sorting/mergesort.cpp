#include <iostream>
using namespace std;

void merge(int array[], int left, int middle, int right) {
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;
    int leftArray[sizeLeft], rightArray[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeRight; j++)
        rightArray[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < sizeLeft && j < sizeRight) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeft) {
        array[k] = leftArray[i];
        i++; k++;
    }
    while (j < sizeRight) {
        array[k] = rightArray[j];
        j++; k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> array[i];
    
    mergeSort(array, 0, n - 1);
    
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << array[i] << " ";
    return 0;
}