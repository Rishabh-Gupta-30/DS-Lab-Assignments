#include <iostream>
using namespace std;

#define MAX 100
int tree[MAX];

class ArrayTree{
    public:
    ArrayTree(){
        for(int i=0;i<MAX;i++){
            tree[i] = -1;
        }
    }
    void insertion(int num){
    tree[1] = num;
}
void leftinsertion(int index , int num){
    int left = 2*index;
    if(left<MAX){
        tree[left] = num;
    }
    else{
        cout<<"Index Not In Range"<<endl;
    }
}
void rightinsertion(int index , int num){
    int right = 2*index+1;
    if(right<MAX){
        tree[right] = num;
    }
    else{
        cout<<"Index Not In Range"<<endl;
    }
}
void preorder(int index = 1){
    if((index>= MAX) || (tree[index]==-1)){
        return;
    }
    cout<<tree[index]<<" ";
    preorder(2*index);
    preorder(2*index+1);
}
void postorder(int index = 1){
    if((index>= MAX) || (tree[index]==-1)){
        return;
    }
    postorder(2*index);
    postorder(2*index+1);
    cout<<tree[index]<<" ";
}
void inorder(int index = 1){
    if((index>= MAX) || (tree[index]==-1)){
        return;
    }
    inorder(2*index);
    cout<<tree[index]<<" ";
    inorder(2*index+1);
}
};
int main() {
    ArrayTree at;
    int choice;
    do{
        cout<<"Enter Choice :"<<endl;
        cout<<"Enter 1 for Insertion of root"<<endl;
        cout<<"Enter 2 for Insertion at left"<<endl;
        cout<<"Enter 3 for Insertion at right"<<endl;
        cout<<"Enter 4 for preorder Traversal"<<endl;
        cout<<"Enter 5 for Inorder Traversal"<<endl;
        cout<<"Enter 6 for Postorder Traversal"<<endl;
        cout<<"Enter 0 for exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
            int num;
            cout<<"Enter value to insert: ";
            cin>>num;
            at.insertion(num);
            break;
            }
            case 2:{
                int Pindex;
                cout<<"Enter Parent index: ";
                cin>>Pindex;
                int leftval;
                cout<<"Enter left value: ";
                cin>>leftval;
                at.leftinsertion(Pindex,leftval);
                break;
            }
            case 3:{
                int Pindex;
                cout<<"Enter Parent index: ";
                cin>>Pindex;
                int rightval;
                cout<<"Enter right value: ";
                cin>>rightval;
                at.rightinsertion(Pindex,rightval);
                break;
            }
            case 4:{
                cout<<"PreOrder Traversal: ";
                at.preorder();
                break;
            }
            case 5:{
                cout<<"InOrder Traversal: ";
                at.inorder();
                break;
            }
            case 6:{
                cout<<"PostOrder Traversal: ";
                at.postorder();
                break;
            }
            case 7:{
                cout<<"Exiting"<<endl;
                break;
            }
            default:{
                cout<<"Wrong Choice";
            }
        }
    }while(choice != 7);
    return 0;
}
