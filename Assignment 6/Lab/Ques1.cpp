#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int num){
            data = num;
            next = nullptr;
            prev = nullptr;
        }
};
class DoublyLL{
    public:
        Node*head;
        DoublyLL(){
            head = nullptr;
        }
};
void InsertAtBegin(int num,Node* head){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        head->next = nullptr;
        head->prev = nullptr;
    }
    else{
    newNode->next = head;
    newNode->prev = nullptr;
    head = newNode;
    }
}
void InsertAtEnd(int num,Node* head){
    Node* newNode = new Node(num);
    Node* temp = head;
    if(temp == nullptr){
        InsertAtBegin(num,head);
    }
    else{
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nullptr;
    }
}
void InsertInBetween(int num,int key,Node* head){
        Node* newNode = new Node(num);
        Node* temp = head;
        if(head == nullptr){
            cout<<"Doubly LL is Empty"<<endl;
        }
        for(int i=1;i<key;i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev= newNode;
        temp->next=newNode;
        newNode->prev=temp;
}
void DeleteNode(int num,Node* head){
    Node*temp = head;
    if(head == nullptr){
        cout<<"DoublyLL is Empty"<<endl;
    }
    else if(head->data == num){
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    else{
    while(temp->data != num){
        temp = temp->next;
    }
    if(temp->next = nullptr){
        temp->prev->next = nullptr;
        delete temp;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        }
    }
}
void SearchNode(int num,Node* head){
    Node* temp = head;
    int count = 1;
    while(temp->data != num || temp == nullptr){
        temp = temp->next;
        count++;
    }
    if(temp == nullptr){
        cout<<"NO DATA FOUND"<<endl;
    }
    else{
        cout<<num<<" is present at : "<<count<<" number node";
    }
}
void printDLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
    }
}
int main() {
    int choice,num,key;
    Node* head = nullptr;
    do{
        cout<<"Enter 1 for Insertion at Beginning"<<endl;
        cout<<"Enter 2 for Insertion at End"<<endl;
        cout<<"Enter 3 for Insertion in Between"<<endl;
        cout<<"Enter 4 for Deletion of Node"<<endl;
        cout<<"Enter 5 for Searching for a Value"<<endl;
        cout<<"Enter 6 for Printing the DLL"<<endl;
        cout<<"Enter 7 for Exiting the Program"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter value for insertion: ";
                cin>>num;
                InsertAtBegin(num,head);
                break;
            }
            case 2:{
                cout<<"Enter value for insertion: ";
                cin>>num;
                InsertAtEnd(num,head);
                break;
            }
            case 3:{
                cout<<"Enter value for insertion: ";
                cin>>num;
                cout<<endl;
                cout<<"Enter position where to insert: ";
                cin>>key;
                InsertInBetween(num,key,head);
                break;
            }
            case 4:{
                cout<<"Enter value to delete: ";
                cin>>num;
                DeleteNode(num,head);
                break;
            }
            case 5:{
                cout<<"Enter Value for Searching: ";
                cin>>num;
                SearchNode(num,head);
                break;
            }
            case 6:{
                printDLL(head);
                break;
            }
    }
    }while(choice != 7);
    return 0;
}
