#include <iostream>
using namespace std;

class HashTable{
    int table[10];

public:
    HashTable(){
        for(int i=0;i<10;i++)
            table[i]=-1;
    }

void insert(int x){
    int index=x%10;
    int start=index;

    while(table[index]!=-1){
        index=(index+1)%10;

        if(index==start){
            cout<<"Table Full\n";
            return;
        }
    }

    table[index]=x;
}

void display(){
    for(int i=0;i<10;i++)
        cout<<i<<" : "<<table[i]<<endl;
}
};

int main(){
    HashTable h;
    int n,x;
    cout<<"Enter number of vehicles: ";
    cin>>n;
    cout<<"Enter registration numbers: ";
    for(int i=0;i<n;i++){
        cin>>x;
        h.insert(x);
    }
    cout<<"Hash Table:\n";
    h.display();
    return 0;
}
