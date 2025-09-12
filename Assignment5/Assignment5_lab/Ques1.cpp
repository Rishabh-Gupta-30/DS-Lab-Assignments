#include <iostream>
using namespace std;
struct SingleLL{
    int data;
    SingleLL *next;
};
SingleLL *head = nullptr;
void InsertAtBeginning(Value){
    SingleLL* NewNode = new SingleLL();
    NewNode->data = Value;
    NewNode->next = head;
    head = NewNode;
}
void InsertAtEnd(Value){
    if(head == nullptr){
        SingleLL *NewNode = new SingleLL();
        NewNode->data = Value;
        NewNode->next = head;
        head = NewNode;
    }
    else{
        SingleLL *NewNode = new SingleLL();
        NewNode->data = Value;
        SingleLL *temp = head;
        while(temp->next == nullptr){
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}
void InsertInBetween(key,Value){
    SingleLL *NewNode = new SingleLL();
    NewNode->data = Value;
    SingleLL *temp = head;
    int count = 1;
    if(key == 1){
        InsertAtBeginning(Value);
    }
    while(count<key-1){
        temp = temp->next;
        count++;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}
void DeleteFromBeginning(){
    if(head == nullptr){
        cout<<"Linked List is Empty."<<endl;
        return;
    }
    SingleLL *temp = head;
    head = head->next;
    delete temp;
}
void DeleteFromEnd(){
    if(head == nullptr){
        cout<<"Linked List is Empty."<<endl;
        return;
    }
    SingleLL *temp = head;
    while(temp->next == nullptr){
            temp = temp->next;
        }
    delete temp;
}
void DeleteInBetween(key){
    if(head == nullptr){
        cout<<"Linked List is Empty."<<endl;
        return;
    }
    SingleLL *temp = head;
    int count = 1;
    if(key == 1){
        DeleteFromBeginning();
    }
    while(count<key){
        temp = temp->next;
        count++;
    }
    delete temp;
}
void SpecificNodeVal(key){
    
}
void Display(){
    
}
int main(){
    int choice,value,key;
    do{
    cout<<"---Menu---"<<endl;
    cout<<"1.Insertion at beginning."<<endl;
    cout<<"2.Insertion at end."<<endl;
    cout<<"3.Insertion in between."<<endl;
    cout<<"4.Deletion from beginning."<<endl;
    cout<<"5.Deletion from end."<<endl;
    cout<<"6.Deletion in between."<<endl;
    cout<<"7.Specific Node Value."<<endl;
    cout<<"8.Displaying all values."<<endl;
    cout<<"0.Exit the program..."<<endl;
    cout<<"Enter the Choice to perform: "
    cin>>choice;
    switch (choice):
        case 1:
            cout<<"Enter the Value to Insert: ";
            cin>>value;
            InsterAtBeginning(Value);
            break;
        case 2:
            cout<<"Enter the Value to Insert: ";
            cin>>value;
            InsterAtEnd(Value);
            break;
        case 3:
            cout<<"Enter the Value to Insert: ";
            cin>>value;
            cout<<endl;
            cout<<"Enter at which node to be inserted: ";
            cin>>key;
            InsterInBetween(key,Value);
            break;
        case 4:
            cout<<"Deleting From Beginning..."<<endl;
            DeleteFromBeginning();
            break;
        case 5:
            cout<<"Deleting From End..."<<endl;
            DeleteFromEnd();
            break;
        case 6:
            cout<<"Enter the Key to be deleted: ";
            cin>>key;
            cout<<"Deleting in between..."<<endl;
            DeleteInBetween(key);
            break;
        case 7:
            cout<<"Enter the Node Key : ";
            cin>>key;
            SpecificNodeVal(key);
            break;
        case 8:
            cout<<"Displaying all the values: "<<endl;
            Display();
            break;
        case 0:
            cout<<"Exiting the Program..."<<endl;
            break;
        default:
            cout<<"Enter the Suitable Number"<<endl;
    }while(choice != 0);
    return 0;
}
