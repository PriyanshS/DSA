#include<iostream>
using namespace std;
int main(){
    int arr[10];
    cout<<"Priyansh Saxena, BTech CE B2"<<endl;
    for(int i=0;i<10;i++){
        cout<<"Enter a element"<<endl;
        cin>>arr[i];
    }
    cout<<"The elements of Array are:";
    for(int j=0;j<10;j++){
        cout<<arr[j]<<", ";
    }
    return 0;
}