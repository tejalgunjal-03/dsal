#include<iostream>
#include<stack>
using namespace std;
const int MAX=100;
int adj[MAX][MAX];
bool visited[MAX];
int numVertices;

void dfs(){
    stack<int> stack;
    for(int i=0;i<numVertices;i++){
        visited[i]=false;
    }
    cout<<"DFS TRAVERSAL:";
    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            stack.push(i);
            visited[i]=true;

            while(!stack.empty()){
                int current=stack.top();
                stack.pop();
                cout<<current<<" ";

                for(int j=numVertices-1;j>=0;j--){
                    if(adj[current][j] == 1 && !visited[j]){
                        stack.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
    }
    cout<<endl;
}

int main(){
    
    cout<<"Enter the no. of vertices:";
    cin>>numVertices;

    cout<<"Enter the adjacent matrix:";
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            cin>>adj[i][j];
            
        }
    }
    dfs();
    return 0;
}