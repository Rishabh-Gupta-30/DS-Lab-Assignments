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
void rotateLL(Node* &head1, int k,int totalNodes){
    if(k==totalNodes){
        printallNodes(head1);
    }
    if(k>totalNodes){
        cout<<"Rotation Not Possible"<<endl;
    }
    Node* temp1 = head1;
    for(int i =0;i<k-1;i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    Node* fake = temp2;
    while(fake->next!= NULL){
        fake = fake->next;
    }
    fake->next = head1;
    temp1->next = NULL;
    printallNodes(temp2);
}
int main() {
    int k;
    cout<<"Enter the size of groups:";
    cin>>k;
    cout<<endl;
    int totalNodes=5;
    Node* head1 = new Node(50);
    insertionfrombeg(head1,40);
    insertionfrombeg(head1,30);
    insertionfrombeg(head1,20);
    insertionfrombeg(head1,10);
    printallNodes(head1);
    rotateLL(head1,k,totalNodes);
    return 0;
}
