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

typedef struct Queue{
    int data[MAXSIZE];
    int front, rear;
}Queue;

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


/*
6.2 判断无向图能否被二分 即相邻节点的两个颜色各不相同
任意节点开始遍历 检查该节点的相邻节点
若未染色 染成不同颜色
若染色 颜色不同 继续判断
颜色相同 不是二分图
*/
int color[MAXSIZE];
#define MAXV 100
int color[MAXV]; // 用于记录每个顶点的颜色，-1 表示未染色

bool isBipartite(Graph G) {
    for (int i = 0; i < G.vexnum; i++) {
        color[i] = -1; // 初始化所有节点未染色
    }

    for (int i = 0; i < G.vexnum; i++) {
        if (color[i] == -1) {
            Queue Q;
            Q.front = Q.rear = 0;
            Q.data[Q.rear++] = i;
            color[i] = 0;
            while (Q.front < Q.rear) {
                int u = Q.data[Q.front++];
                for (int v = 0; v < G.vexnum; v++) {
                    if (G.arc[u][v] == 1) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; // 染成相反颜色
                            Q.data[Q.rear++] = v;
                        } else if (color[v] == color[u]) {
                            return false; // 相邻顶点染色相同，不是二分图
                        }
                    }
                }
            }
        }
    }
    return true;
}

/*
6.3 判断无向图是否为树
*/
bool visited[MAXSIZE];
void Dfs(Graph G, int i){
    visited[i]=true;
    cout<<G.vex[i]<<" ";
    for(int j=0;j<G.vexnum;j++){
        if(!visited[j] && G.arc[i][j]==1){
            Dfs(G,j);
        }
    }
}

bool isTree(Graph G) {
    if (G.arcnum != G.vexnum - 1) 
        return false;
    Dfs(G, 0);
    for(int i=0;i<G.vexnum;i++)
        if(!visited[i])
            return false;
    return true;
}

/*
6.4 判断是否存在i到j的路径
*/
bool isPath(Graph G, int i, int j){
    Dfs(G, i);
    return visited[j];
}

/*
6.5 输出i到j的所有简单路径  邻接表
*/

void Findpath(ALGraph G, int i, int j, int d, int path[]){
    path[d++]=i;
    visited[i]=true;
    if(i==j)
        print(path[]);
    ArcNode *p=G.adjlist[i].firstarc;
    while(p){
        int w=p->adjvex;
        if(!visited[w]){
            Findpath(G, w, j, d, path);
        }
        p=p->nextarc;
    }
    visited[i]=false;//回溯
}

/*
判断拓扑序列是否唯一
*/

typedef struct {
    int numvertices; int numedges;
    char VerticesList[MAXV];
    int Edges[MAXV][MAXV];
}MGraph;

int Uniquely(MGraph G){
    int inDegree[MAXV];
    for(int i=0;i<G.numvertices;i++){
        inDegree[i]=0;
    }
    for(int i=0;i<G.numvertices;i++){
        for(int j=0;j<G.numvertices;j++){
            if(G.Edges[i][j]==1)
                ++inDegree[j];
        }
    }
    int Queue[MAXV];
    int front=0, rear=0;
    int count=0;
    for(int i=0;i<G.numvertices;i++)
        if(inDegree[i]==0)
            Queue[rear++]=i;
    while(front<rear){
        if(rear-front>1)
            return 0;
        count++;
        int k=Queue[front++];
        for(int i=0;i<G.numvertices;i++){
            if(G.Edges[k][i]){
                --inDegree[i];
                if(inDegree[i]==0)
                    Queue[rear++]=i;
            }
        }
    }
    if(count==G.numvertices)
        return 1;
    else
        return 0;
}