#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*right;
    
    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};
void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main() {
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    
    cout<<"Printing the Preorder: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing the Inorder: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Printing the Postorder: "<<endl;
    postorder(root);
    
    return 0;
}
