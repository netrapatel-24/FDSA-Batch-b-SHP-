#include<iostream>
#include<string>
using namespace std;

int main(){
string s[50],d;
int n;
cout<<"Enter number of strings:";
cin>>n;
cout<<"Enter string:";
for(int i=0;i<n;i++){
    cin>>s[i];
}
cout<<endl;
for(int i=0;i<n;i++){
    cout<<s[i]<<endl;
}
cout<<"Enter the word to search";
cin>>d;
for(int i=0;i<n;i++){
    if(s[i]==d){
        cout<<"found at "<<i+1<<"Position";
    }
}
}
