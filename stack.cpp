#include<iostream>
using namespace std;
int top=-1;
int stack[100];
void DisplayStack(int stack[]){
    int i;
    cout<<"The stack is: ";
    for(i=0;i<=top;i++){
        cout<<stack[i]<<" ";
    }
}
int pop(int stack[]){
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
     DisplayStack(stack);
}
int push( int value){
    if(top==99){
        cout<<"Stack Overflow"<<endl;
           }
    else{
        top=top+1;
        stack[top]=value;
        DisplayStack(stack);

    }
     return 0;
}
int peek(){
    cout<<stack[top];
    return 0;
}
int main(){
    int value,  Choice;
    cout<<"Enter the value of element"<<endl;
    cin>>value;
    push(value);
    cout<<"Enter your choice, which function do you want to perform?"<<endl;
    cout<<"1)push 2)pop 3)peek";
    cin>>Choice;
    switch(Choice){
        case 1:
        cout<<"Enter the value of element"<<endl;
        cin>>value;
        push(value);
        DisplayStack(stack);
        break;
        case 2:
        pop(stack);
        break;
        case 3:
        peek();
        break;
        default:
        cout<<"Exiting ";

    }
    
    return 0;
}