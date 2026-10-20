#include <iostream>
#include <queue>
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

class Tree{
public:
    Node *root;
    Tree(){
        root=NULL;
    }

void inorder(Node *p){
    if(p==NULL)
        return;
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}

void preorder(Node *p){
    if(p==NULL)
        return;
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}

void postorder(Node *p){
    if(p==NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
}

void levelorder(){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *p=q.front();
        q.pop();

        cout<<p->data<<" ";

        if(p->left!=NULL)
            q.push(p->left);

        if(p->right!=NULL)
            q.push(p->right);
        }
    }
};

int main(){
    Tree t;

    t.root=new Node(1);
    t.root->left=new Node(2);
    t.root->right=new Node(3);
    t.root->left->left=new Node(4);
    t.root->left->right=new Node(5);
    t.root->right->left=new Node(6);
    t.root->right->right=new Node(7);

    cout<<"Inorder: ";
    t.inorder(t.root);
    cout<<"\nPreorder: ";
    t.preorder(t.root);
    cout<<"\nPostorder: ";
    t.postorder(t.root);
    cout<<"\nLevel order: ";
    t.levelorder();

    return 0;
}
