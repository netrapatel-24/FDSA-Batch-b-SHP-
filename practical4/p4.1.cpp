#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class ll{
    Node *head;
public:
    ll(){
        head = NULL;
    }
    void insertFront(int x){
        Node *n = new Node(x);
        n->next = head;
        head = n;
    }

    void insertEnd(int x){
        Node *n = new Node(x);
        if(head == NULL){
            head = n;
            return;
        }
        Node *t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = n;
    }

    void insertPos(int x,int p){
        if(p < 1){
            cout << "Invalid position" << endl;
            return;
        }
        if(p == 1){
            insertFront(x);
            return;
        }
        Node *t = head;
        int i = 1;
        while(t != NULL && i < p - 1){
            t = t->next;
            i++;
        }
        if(t == NULL){
            cout << "Invalid position" << endl;
            return;
        }
        Node *n = new Node(x);
        n->next = t->next;
        t->next = n;
    }
    void display(){
        Node *t = head;
        if(t == NULL){
            cout << "List is empty" << endl;
            return;
        }
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{
    ll l;
    l.insertEnd(101);
    l.display();
    l.insertEnd(102);
    l.display();
    l.insertFront(100);
    l.display();
    l.insertPos(150,2);
    l.display();
    return 0;
}
