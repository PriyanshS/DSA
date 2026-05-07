#include<iostream>
using namespace std;
int main(){
    cout<<"Priyansh Saxena, BTech CE B2"<<endl;
    int n;
    cout<<"Enter the SIze of Array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Now input the elements of this array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the element"<<endl;
        cin>>arr[i];
    }
    cout<<"Now, displaying in reverse order...."<<endl;
    for(int j=n-1;j>=0;j--){
        cout<<arr[j]<<", ";
    }
    return 0;
}