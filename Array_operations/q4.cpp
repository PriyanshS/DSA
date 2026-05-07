#include<iostream>
#include<array>
using namespace std;
// Insertion Sort
void insertionSort( ) {
    int n;
    cout<<"Enter the SIze of Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Now input the elements of this array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the element"<<endl;
        cin>>arr[i];
    }
    
    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // The while loop condition performs the comparison
        // Note: Even if the condition is false, 1 comparison happened
        while (j >= 0) {
            comparisons++; // Increment for every check of arr[j] > key
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++; // Increment for every element moved
                j = j - 1;
            } else {
                break; // Comparison happened, but no shift needed
            }
        }
        arr[j + 1] = key;
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts (Swaps): " << shifts << endl;
}
int main(){
cout<<"Priyansh Saxena BTech CE B2"<<endl;
insertionSort();
return 0;

}
