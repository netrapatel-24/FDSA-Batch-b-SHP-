#include<iostream>
using namespace std;

class Node{
public:
    string name;
    Node *next,*prev;

    Node(string s){
        name=s;
        next=prev=NULL;
    }
};

class CircularList{
    Node *head;
public:
    Circularlist(){
        head=NULL;
    }
void join(string s){
    Node *n=new Node(s);
    if(head==NULL){
        head=n;
        n->next=head;
        n->prev=head;
        return;
    }
    Node *p=head;
    while(p->next!=head){
        p=p->next;}

    p->next=n;
    n->prev=p;
    n->next=head;
    head->prev=n;
}

void leave(string s){
    if(head==NULL)
        return;
    Node *p=head;
    do{
        if(p->name==s)
            break;
        p=p->next;
    }while(p!=head);
    if(p->name!=s){
        cout<<"Student not found\n";
        return;
    }
    if(p->next==p){
        head=NULL;
        delete p;
        return;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    if(p==head){
        head=p->next;
    }
    delete p;
}

void display(){
    if(head==NULL){
        cout<<"Circle empty\n";
        return;
    }
    Node *p=head;
    do{
        cout<<p->name<<" ";
        p=p->next;
    }while(p!=head);

    cout<<"\n";
    }
};

int main(){
    Circularlist c;
    int ch;
    string s;
    do{
        cout<<"1.Join 2.Leave 3.Display 0.Exit\n";
        cin>>ch;

        if(ch==1){
            cin>>s;
            c.join(s);
        }
        else if(ch==2){
            cin>>s;
            c.leave(s);
        }
        else if(ch==3)
            c.display();

    }while(ch!=0);

    return 0;
}
