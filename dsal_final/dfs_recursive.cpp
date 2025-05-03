#include<iostream>
using namespace std;
const int MAX =100;
int adj[MAX][MAX];
int visited[MAX];
int numVertices;

void dfs(int vertex){
    visited[vertex]=1;
    cout<<vertex<<" ";
    for(int i=0;i<numVertices;i++){
        if(adj[vertex][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    cout<<"Enter number of vertices:";
    cin>>numVertices;
    cout<<"Enter adjacency matrix:"<<endl;
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            cin>>adj[i][j];
        }
    }

    cout<<"DFS TRAVERSAL:";
    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    return 0;
}