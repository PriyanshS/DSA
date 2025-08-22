#include<iostream>
using namespace std;
int top=-1;
int stack[100];
int DisplayStack(){
    int i;
    cout<<"The stack is: ";
    for(i=0;i<=top;i++){
        cout<<stack[i]<<" ";
    }
    return 0;
}
int pop(int stack[], int SizeOfStack){
    int Var;
    if(top==-1){
        cout<<"Stack Overflow";
        return 0;
    }
    else{
        Var=stack[top];
        top=top-1;
        return 0;
    }
     DisplayStack();
}
int push( int value){
    if(top==99){
        cout<<"Stack Overflow"<<endl;
           }
    else{
        top=top+1;
        stack[top]=value;

    }
     return 0;
}
int main(){
    int value, SizeOfStack, Choice, PlaceValue;
    //cout<<"Enter the size of stack"<<endl;
        //cin>>SizeOfStack;
   // int stack[SizeOfStack];
    cout<<"Enter your choice, which function do you want to perform?"<<endl;
    cout<<"1)push 2)pop";
    cin>>Choice;
    switch(Choice){
        case 1:
        cout<<"Enter the value of element"<<endl;
        cin>>value;
        push(value);
        DisplayStack();
        break;
        case 2:
        pop(stack, SizeOfStack);
        DisplayStack();
        break;
    }
    
    return 0;
}