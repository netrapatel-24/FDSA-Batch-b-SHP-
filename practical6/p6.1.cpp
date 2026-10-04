#include<iostream>
using namespace std;

class Stack{
    int a[100];
    int top;
    int size;
public:
    Stack(int n){
        size=n;
        top=-1;
    }

void push(int x){
    if(top==size-1)
        cout<<"Stack Overflow\n";
    else{
        top++;
        a[top]=x;
    }
}

void pop(){
    if(top==-1)
        cout<<"Stack Underflow\n";
    else{
        cout<<"Removed: "<<a[top]<<"\n";
        top--;
    }
}

void display(){
    if(top==-1)
        cout<<"Stack empty\n";
    else
        cout<<"Top: "<<a[top]<<"\n";
    }
};

int main(){
    int n,ch,x;
    cin>>n;

    Stack s(n);

    do{
        cout<<"1.Push 2.Pop 3.Display 0.Exit\n";
        cin>>ch;

        if(ch==1){
            cin>>x;
            s.push(x);
        }
        else if(ch==2)
            s.pop();
        else if(ch==3)
            s.display();

    }while(ch!=0);

    return 0;
}
