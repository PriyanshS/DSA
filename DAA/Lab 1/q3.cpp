#include<iostream>
using namespace std;
int main(){
    cout<<"Priyansh Saxena BTechCE B2"<<endl;
    int n;
    cout<<"Enter the SIze of Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Now input the elements of this array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the element"<<endl;
        cin>>arr[i];
    }
    int sum=0;
    for(int j=0;j<n;j++){
        sum=sum+arr[j];
    }
    cout<<"Now, sum of array is "<<sum<<endl;
    return 0;
}