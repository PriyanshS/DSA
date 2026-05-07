#include <iostream>
using namespace std;
int DeleteFromArray(int Array[], int LengthOfArray, int Index){
    int i;
    for(i=Index+1;i<LengthOfArray;i++){
        Array[i-1]=Array[i];
    }
    cout<<"The Updated array is: ";
    for(int i=0; i<LengthOfArray+1; i++){       
        cout<<Array[i]<<" ";    
    }
    return 0;
}
int SmallestElement(int Array[], int LengthOfArray){
    int i;
    int SmallestElement=Array[i];
    for(i=0;i<LengthOfArray;i++){
        if(Array[i]< SmallestElement){
            SmallestElement=Array[i];
        }
    }
    cout<<"The smallest element of array is: "<<SmallestElement<<endl;
    return 0;
}
int SecondLargestElement(int Array[],int LengthOfArray){
    int i, LargestElement=0, SecondLargestElement=0, IndexOfLargestElement;
    for(i=0;i<LengthOfArray;i++){
        if(Array[i]>LargestElement){
            LargestElement=Array[i];
            IndexOfLargestElement=i;
        }
    }
    for(i=IndexOfLargestElement+1;i<LengthOfArray;i++){
        Array[i-1]=Array[i];
    }
    for(i=0;i<LengthOfArray;i++){
        if(Array[i]>SecondLargestElement){
            SecondLargestElement=Array[i];
        }
    }
    cout<<"Second Largest Element of the Array is "<<SecondLargestElement<<endl;
    return 0;

    }

int InsertIntoArray(int Array[], int LengthOfArray, int Element, int Index){
    int i;
    for(i=LengthOfArray-1; i>=Index; i--){
        Array[i+1] = Array[i];
    }
    Array[Index] = Element;
    cout<<Element<<" is inserted at index "<<Index<<endl;
    cout<<"The Updated array is: ";
    for(int i=0; i<LengthOfArray+1; i++){       //LengthOfArray+1 because we are inserting an element at the end of the array.
        cout<<Array[i]<<" ";    
    }
    return 0;
}
int HighestAndLowestElements(int Array[], int LengthOfArray){
    int i, LargestElement=0;
    int SmallestElement=Array[i]; 
    for(i=0;i<LengthOfArray;i++){
        if(Array[i]< SmallestElement){
            SmallestElement=Array[i];
        }
    }
    for(i=0;i<LengthOfArray;i++){
        if(Array[i]>LargestElement){
            LargestElement=Array[i];
        }
    }
    cout<<"Highest element of array is:  "<<LargestElement<<"And lowest element of array is:  "<<SmallestElement<<endl;
    return 0;
}
int main(){
    int SizeOfArray, LengthOfArray;
    cout<<"Enter the size of the array: ";
    cin>>SizeOfArray;
    cout<<"Enter the length of the array: ";
    cin>>LengthOfArray;
    int Array[SizeOfArray];
    for(int i=0; i<LengthOfArray; i++){
        cout<<"Enter the element at index "<<i<<": ";
        cin>>Array[i];
    }
    cout<<"The array is: ";
    for(int i=0; i<LengthOfArray; i++){
        cout<<Array[i]<<" ";
    }
    //In order to insert an element into the array, we need to shift the elements to the right and then insert the element at the desired index.
    int Element, Index, Function;
    cout<<"Select the function to be performed: "<<endl;
    cout<<"1)Insertion 2)Deletion 3)Smallest Element "<<endl;
    cout<<"4)Highest/Lowest Element 5)Second Largest Element"<<endl;
    cout<<"Enter the number: "<<endl;
    cin>>Function;
    switch(Function){
        case 1:
        cout<<"Enter the element to be inserted: ";
        cin>>Element;
        cout<<"Enter the index at which the element is to be inserted: ";
        cin>>Index;
        InsertIntoArray(Array, LengthOfArray, Element, Index);
        break;
        case 2:
        cout<<"Enter the index at which the element is to be deleted: ";
        cin>>Index;
        DeleteFromArray(Array, LengthOfArray,Index);
        break;
        case 3:
        SmallestElement(Array, LengthOfArray);
        break;
        case 4:
        HighestAndLowestElements(Array, LengthOfArray);
        break;
        case 5:
        SecondLargestElement(Array, LengthOfArray);
        break;
    }
    return 0;
}