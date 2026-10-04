#include<iostream>
using namespace std;

class Node{
public:
    string page;
    Node *next;

    Node(string p){
        page=p;
        next=NULL;
    }
};

class Stack{
    Node *top;
public:
    Stack(){
        top=NULL;
    }

void visit(string p){
    Node *n=new Node(p);
    n->next=top;
    top=n;
}

void back(){
    if(top==NULL){
        cout<<"No history\n";
        return;
    }

    Node *p=top;
    cout<<"Back from: "<<p->page<<"\n";
    top=top->next;
    delete p;
}

void display(){
    if(top==NULL){
        cout<<"No page\n";
        return;
    }

    cout<<"Current page: "<<top->page<<"\n";
    }
};

int main(){
    Stack s;
    int ch;
    string p;
    do{
        cout<<"1.Visit 2.Back 3.Display 0.Exit\n";
        cin>>ch;

        if(ch==1){
            cin>>p;
            s.visit(p);
        }
        else if(ch==2)
            s.back();
        else if(ch==3)
            s.display();

    }while(ch!=0);

    return 0;
}
