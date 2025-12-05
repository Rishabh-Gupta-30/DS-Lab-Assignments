#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = NULL;
  }
};
void insertionfrombeg(Node* &head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    }
    newNode->next = head;
    head = newNode;
}
void printallNodes(Node* &head){
    if(head == NULL){
        cout<<"There are Nodes in Linked List"<<endl;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int compareNodes(Node* &head1 , Node* &head2){
    Node* temp1 = head1;
    while(temp1 != NULL){
        Node* temp2 = head2;
        while(temp2 != NULL){
            if(temp2 == temp1){
                return temp1->data;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return -1;
}
int main() {
    Node* head1 = new Node(5);
    insertionfrombeg(head1,8);
    insertionfrombeg(head1,1);
    insertionfrombeg(head1,4);
    printallNodes(head1);
    Node* head2 = new Node(5);
    insertionfrombeg(head2,8);
    insertionfrombeg(head2,1);
    insertionfrombeg(head2,6);
    insertionfrombeg(head2,5);
    printallNodes(head2);
    cout<<compareNodes(head1,head2);
    return 0;
}
