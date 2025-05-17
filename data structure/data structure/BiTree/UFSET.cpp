#include <iostream>
using namespace std;

#define SIZE 10000
int UFSETS[SIZE];

void Initial(int S[]){
    memset(S, -1, sizeof(int));
}

int Find(int S[], int x){
    while(S[x]>=0)
        x=S[x];
    return x;
}//返回x的根

void Union(int S[], int r1, int r2){
    if(S[r1]<S[r2]){
        S[r1]+=S[r2];
        S[r2]=r1;
    }
    else{
        S[r2]+=S[r1];
        S[r1]=r2;
    }
}

int Find_(int S[], int x){
    int root=x;
    while(S[root]>=0)
        root=S[root];
    while(S[x]>=0){
        int t=S[x];
        S[x]=root;
        x=t;
    }
}//路径压缩