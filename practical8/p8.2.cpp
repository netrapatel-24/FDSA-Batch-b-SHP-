#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class bst{
public:
    Node *root;
    bst(){
        root=NULL;
    }

    Node* insert(Node *p,int x){
    if(p==NULL)
        return new Node(x);

    if(x<p->data)
        p->left=insert(p->left,x);
    else if(x>p->data)
        p->right=insert(p->right,x);
    return p;
}

void add(int x){
    root=insert(root,x);
}

void inorder(Node *p){
    if(p==NULL)
        return;
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}
};

int main(){
    bst t;
    int n,x;

    cout<<"Enter number of books: ";
    cin>>n;
    cout<<"Enter book codes: ";
    for(int i=0;i<n;i++){
        cin>>x;
        t.add(x);
    }
    cout<<"Inorder: ";
    t.inorder(t.root);

    return 0;
}
