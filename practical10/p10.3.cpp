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
    int h1=x%10;
    int h2=7-(x%7);

    for(int i=0;i<10;i++){
        int index=(h1+i*h2)%10;

        if(table[index]==-1){
            table[index]=x;
            return;
        }
    }
    cout<<"Table Full\n";
}

void display(){
    for(int i=0;i<10;i++)
        cout<<i<<" : "<<table[i]<<endl;
}
};

int main(){
    HashTable h;
    int n,x;
    cout<<"Enter number of students: ";
    cin>>n;
    cout<<"Enter student IDs: ";
    for(int i=0;i<n;i++){
        cin>>x;
        h.insert(x);
    }
    cout<<"Hash Table:\n";
    h.display();
    return 0;
}
