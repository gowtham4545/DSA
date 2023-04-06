#include<iostream>
#include<vector>
using namespace std;
/*
TODO: To find the shortest distance from any single node
*/
// TODO: To find the shortest distance from any single node

int find(int v,int cost[],bool visited[]){
    int minVertex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i])
            if(minVertex==-1 || cost[i]<cost[minVertex])
                minVertex=i;
    }
    return minVertex;
}

void dijkstra(int** edges,int v){
    int cost[v];
    bool visited[v];
    for(int i=0;i<v;i++){
        cost[i]=INT32_MAX;
        visited[i]=false;
    }
    cost[0]=0;
    for(int i=0;i<v-1;i++){
        int minVertex=find(v,cost,visited);
        visited[minVertex]=true;
        for(int j=0;j<v;j++){
            if(edges[minVertex][j] && !visited[j])
                cost[j]=min(cost[j],cost[minVertex]+edges[minVertex][j]);
        }
    }
    cout<<"The costs of all nodes from node 0 are :"<<endl;
    for(int i=0;i<v;i++)
        cout<<"\t"<<i<<" : "<<cost[i]<<endl;
}

int main()
{
    int v,e;
    cin>>v>>e;

    int** edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d]=w;
        edges[d][s]=w;
    }
    dijkstra(edges,v);
    return 0;
}