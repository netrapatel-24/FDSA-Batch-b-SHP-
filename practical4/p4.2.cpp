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

    void deleteValue(int x){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        if(head->data == x){
            Node *t = head;
            head = head->next;
            delete t;
            return;
        }
        Node *t = head;
        while(t->next != NULL && t->next->data != x){
            t = t->next;
        }
        if(t->next == NULL){
            cout << "Value not found" << endl;
            return;
        }
        Node *n = t->next;
        t->next = n->next;
        delete n;
    }

    void display(){
        Node *t = head;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
    void rev(Node *t){
        if(t == NULL){
            return;
        }
        rev(t->next);
        cout << t->data << " ";
    }
    void revshow(){
        rev(head);
        cout << endl;
    }
};

int main()
{
    ll l;
    l.insertEnd(100);
    l.insertEnd(150);
    l.insertEnd(101);
    l.insertEnd(102);
    cout << "Forward: ";
    l.display();
    l.deleteValue(101);
    cout << "After deletion: ";
    l.display();
    cout << "Reverse: ";
    l.revshow();
    return 0;
}
