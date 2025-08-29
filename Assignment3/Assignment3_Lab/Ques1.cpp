#include <iostream>
using namespace std;
#define MaxLen 10
typedef struct{
    int top;
    int Array[MaxLen];
} Stack;
void init(Stack &s);
void push(Stack &s,int value);
int pop(Stack &s);
bool isEmpty(Stack &s);
bool isFull(Stack &s);
void display(Stack &s);
int peek(Stack &s);

int main() {
    Stack s;
    init(s);
    int choice,value;
    do{
    cout<<"STACK---MENU:"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. PUSH"<<endl;
    cout<<"2. POP"<<endl;
    cout<<"3. ISEMPTY"<<endl;
    cout<<"4. ISFULL"<<endl;
    cout<<"5. DISPLAY"<<endl;
    cout<<"6. PEAK"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>choice;
    
    switch(choice){
        case 0:
        cout<<"Exiting..."<<endl;
        break;
        case 1:
        cout<<"Enter the value to push: ";
        cin>>value;
        push(s,value);
        break;
        case 2:
        value = pop(s);
        if(value!=-1){
            cout<<"Popped "<<value<<endl;
        }
        break;
        case 3:
        if(isEmpty(s)){
            cout<<"Stack is Empty."<<endl;
        }
        else{
            cout<<"Stack is Not Empty."<<endl;
        }
        break;
        case 4:
        if(isFull(s)){
            cout<<"Stack is Full."<<endl;
        }
        else{
            cout<<"Stack is Not Full."<<endl;
        }
        break;
        case 5:
        display(s);
        break;
        case 6:
        value = peek(s);
        if(value!=-1){
            cout<<"Peek Value "<<value<<endl;
        }
        break;
        default:
        cout<<"Invalid Choice..."<<endl;
    }
    }while(choice !=0);
    return 0;
}
void init(Stack &s){
    s.top = -1;
}
void push(Stack &s,int value){
    if(isFull(s)){
        cout<<"Stack is Overflowed cannot add other values"<<endl;
    }
    else{
        s.Array[++s.top]= value;
        cout<<value<<" Pushed into the Stack"<<endl;
    }
}
int pop(Stack &s){
    if(isEmpty(s)){
        cout<<"Stack is Empty cannot pop the top element"<<endl;
        return -1;
    }
    else{
        return s.Array[s.top--];
    }
}
bool isEmpty(Stack &s){
    return s.top == -1;
}
bool isFull(Stack &s){
    return s.top == MaxLen -1;
}
void display(Stack &s){
    if(isEmpty(s)){
        cout<<"Stack is Empty."<<endl;
    }
    else{
        cout<<"Printing Stack Elements"<<endl;
        for(int i=s.top;i>=0;i--){
            cout<<s.Array[i]<<" ";
        }
        cout<<endl;
    }
}
int peek(Stack &s){
    if(isEmpty(s)){
        cout<<"Stack is Empty.."<<endl;
        return -1;
    }
    else{
        return s.Array[s.top];
    }
}

