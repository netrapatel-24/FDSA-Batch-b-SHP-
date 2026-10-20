#include<iostream>
using namespace std;

class Node{
public:
    string song;
    Node *prev,*next;
    Node(string s){
        song=s;
        prev=next=NULL;
    }
};

class playlist{
    Node *head,*tail;
public:
    playlist(){
        head=tail=NULL;
    }
void insertatfirst(string s){
   Node *n=new Node(s);
    if(head==NULL)
        head=tail=n;
    else{
        n->next=head;
        head->prev=n;
        head=n;
    }
}
void insertatlast(string s){
    Node *n=new Node(s);
    if(head==NULL)
        head=tail=n;
    else{
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}

void insertafter(string a,string s){
    Node *p=head;
    while(p!=NULL && p->song!=a)
        p=p->next;
    if(p==NULL){
        cout<<"Song not found\n";
        return;
    }
    Node *n=new Node(s);
    n->next=p->next;
    n->prev=p;

    if(p->next!=NULL)
        p->next->prev=n;
    else
        tail=n;
        p->next=n;
}

void removefirst(){
    if(head==NULL){
        cout<<"Playlist empty\n";
        return;
    }
    Node *p=head;
    head=head->next;
    if(head==NULL)
        tail=NULL;
    else
        head->prev=NULL;

    delete p;
}

void display(){
    Node *p=head;
    while(p!=NULL){
        cout<<p->song<<" ";
        p=p->next;
    }
    cout<<"\n";
}

void count(){
    int c=0;
    Node *p=head;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    cout<<c<<"\n";
}
};

int main(){
    playlist p;
    int ch;
    string s,a;
    do{
        cout<<"1.Add First 2.Add Last 3.Insert After 4.Remove First 5.Display 6.Count 0.Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>s;
            p.insertatfirst(s);
        }
        else if(ch==2){
            cin>>s;
            p.insertatlast(s);
        }
        else if(ch==3){
            cin>>a>>s;
            p.insertafter(a,s);
        }
        else if(ch==4)
            p.removefirst();
        else if(ch==5)
            p.display();
        else if(ch==6)
            p.count();

    }while(ch!=0);
    return 0;
}
