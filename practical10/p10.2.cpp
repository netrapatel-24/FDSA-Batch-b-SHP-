#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

class HashTable{
    Node *table[10];

public:
HashTable(){
    for(int i=0;i<10;i++)
        table[i]=NULL;
}

void insert(int x){
    int index=x%10;

    Node *p=new Node(x);

    if(table[index]==NULL){
        table[index]=p;
    }
    else{
        Node *q=table[index];

        while(q->next!=NULL)
            q=q->next;

        q->next=p;
    }
}

void display(){
    for(int i=0;i<10;i++){
        cout<<i<<" : ";

        Node *p=table[i];

        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }

        cout<<endl;
    }
}
};

int main(){
    HashTable h;
    int n,x;
    cout<<"Enter number of books: ";
    cin>>n;
    cout<<"Enter book codes: ";
    for(int i=0;i<n;i++){
        cin>>x;
        h.insert(x);
    }
    cout<<"Hash Table:\n";
    h.display();
    return 0;
}
