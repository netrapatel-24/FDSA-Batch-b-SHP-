#include <iostream>
#include <queue>
using namespace std;

class Graph{
    int a[20][20];
    int n;
public:
    Graph(int x){
        n=x;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=0;
    }

void edge(int x,int y){
    a[x][y]=1;
    a[y][x]=1;
}

void dfs(int v,bool visited[]){
    cout<<v<<" ";
    visited[v]=true;

    for(int i=0;i<n;i++){
        if(a[v][i]==1 && !visited[i])
            dfs(i,visited);
    }
}

void bfs(int start){
    bool visited[20]={false};
    queue<int> q;

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int v=q.front();
        q.pop();

        cout<<v<<" ";

        for(int i=0;i<n;i++){
            if(a[v][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
};

int main(){
    Graph g(6);

    g.edge(0,1);
    g.edge(0,2);
    g.edge(1,3);
    g.edge(1,4);
    g.edge(2,5);

    bool visited[20]={false};

    cout<<"DFS: ";
    g.dfs(0,visited);

    cout<<"\nBFS: ";
    g.bfs(0);
    return 0;
}
