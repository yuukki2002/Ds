#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXSIZE 10000
typedef struct Graph{
    int vex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vexnum, arcnum;
}Graph; // 邻接矩阵

typedef struct ArcNode{
    int adjvex;
    ArcNode *nextarc;
}ArcNode;
typedef struct VexNode{
    int data;
    ArcNode *firstarc;
}VexNode;
typedef struct ALGraph{
    VexNode adjlist[MAXSIZE];
    int vexnum, arcnum;
}ALGraph; // 邻接表

typedef struct Queue{
    int data[MAXSIZE];
    int front, rear;
}Queue;
bool visited[MAXSIZE];
void BFS(Graph G){
    for(int i=0;i<G.vexnum;i++){
        visited[i]=false;
    }
    Queue Q;
    Q.front=Q.rear=0;
    for(int i=0;i<G.vexnum;i++){
        if(!visited[i]){
            Bfs(G,i,Q);
        }
    }
}

void Bfs(Graph G, int i, Queue &Q){
    visited[i]=true;
    cout<<G.vex[i]<<" ";
    Q.data[Q.rear++]=i;
    while(Q.front<Q.rear){
        int j=Q.data[Q.front++];
        for(int k=0;k<G.vexnum;k++){
                if(visited[k] && G.arc[j][k]==1){
                    visited[k]=true;
                    cout<<G.vex[k]<<" ";
                    Q.data[Q.rear++]=k;
                }
        }
    }
}
/*
void Bfs(Graph G, int i, Queue &Q){
    visited[i]=true;
    cout<<G.vex[i]<<" ";
    Q.data[Q.rear++]=i;
    while(Q.front<Q.rear){
        int j=Q.data[Q.front++];
        for(int k=G.adjlist[j].fisrtarc;k;k=k->nextarc){
                w=k->adjvex;
                if(visited[w]){
                    visited[w]=true;
                    cout<<G.vex[w]<<" ";
                    Q.data[Q.rear++]=w;
                }
        }
    }
}
*/

void DFS(Graph G, int i){
    for(int i=0;i<G.vexnum;i++)
        visited[i]=false;
    for(int i=0;i<G.vexnum;i++){
        if(!visited[i]){
            Dfs(G,i);
        }
    }
}

void Dfs(Graph G, int i){
    visited[i]=true;
    cout<<G.vex[i]<<" ";
    for(int j=0;j<G.vexnum;j++){
        if(!visited[j] && G.arc[i][j]==1){
            Dfs(G,j);
        }
    }
}
/*
void Dfs(Graph G, int i){
    visited[i]=true;
    cout<<G.vex[i]<<" ";
    for(ArcNode *k=G.adjlist[i].firstarc;k;k=k->nextarc){
        int w=k->adjvex;
        if(!visited[w]){
            Dfs(G,w);
        }
    }
}
*/