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
Node* insert(Node* root,int key){
    Node* newNode = new Node(key);
    if(root==nullptr){
        return newNode;
    }
    if(key<root->data){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }
    return root;
}
Node* RecursiveSearch(Node* root,int val){
    if(root == nullptr || root->data == val){
        return root;
    }
    if(val < root->data){
        return RecursiveSearch(root->left,val);
    }
    else{
        return RecursiveSearch(root->right,val);
    }
}
Node* NonRecursiveSearch(Node* root,int val){
    while(root!= nullptr){
        if(val == root->data){
            return root;
        }
        else if(val<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
        return nullptr;
    }
}
Node* findmax(Node* root){
    if(root==nullptr){
        return root;
    }
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}
Node* findmin(Node* root){
    if(root == nullptr){
        return root;
    }
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}
Node* inordersuccessor(Node* root , Node* target){
    if(target->right != nullptr){
        return findmin(target->right);
    }
    Node* successor = nullptr;
    while(root != nullptr){
        if(target->data < root->data){
            successor = root;
            root = root->left;
        }
        else if(target->data > root->data){
            root = root->right;
        }
        else{
            break;
        }
    }
    return successor;
}
Node* inorderpredecessor(Node* root , Node* target){
    if(target->left != nullptr){
        return findmax(target->left);
    }
    Node* predecessor = nullptr;
    while(root != nullptr){
        if(target->data > root->data){
            predecessor = root;
            root = root->right;
        }
        else if(target->data < root->data){
            root = root->left;
        }
        else{
            break;
        }
    }
    return predecessor;
}
int main() {
    int x;
    cout<<" Enter total values: ";
    cin>>x;
    int arr[x];
    cout<<"Enter Node values: "<<endl;
    for(int i =0;i<x;i++){
        cin>>arr[i];
    }
    Node* root = nullptr;
    for(int i = 0;i<x;i++){
        root = insert(root,arr[i]);
    }
    cout<< "Enter Node value to search: ";
    int key;
    cin>>key;
    cout<<"Recursive search : "<<endl;
    cout<<(RecursiveSearch(root,key) ? "Found" : "Not Found");
    cout<<"Non-Recursive search: "<<endl;
    cout<<(NonRecursiveSearch(root,key) ? "Found" : "Not Found");
    return 0;
}
