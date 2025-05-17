#include <stdlib.h>
#include <stack>
#include <iostream>
#define MAXSIZE 10
typedef struct{
    int SqBiTnode[MAXSIZE];
    int ElemNum;
}SqBiTree;

bool IsEmpty(SqBiTree T, int i){
    return !(T.SqBiTnode[i]!=-1 && i<T.ElemNum);
}

void Inorder(SqBiTree T, int *count){
    count = (int*)malloc(sizeof(int)*T.ElemNum);
    stack<int> s;
    int k=0,i=0;
    while(!IsEmpty(T,i) || !StackEmpty(s)){
        if(!IsEmpty(T,i)){
            s.push(i);
            i=i*2;
        }
        else{
            i=s.pop();
            count[k++]=T.SqBiTnode[i];
            i=i*2+1;
        }
    }
}

bool IsBST(SqBiTree T){
    int *count;
    Inorder(T, count);
    bool flag=true;
    for(int i=0;i<T.ElemNum;i++){
        if(count[i]>count[i+1]){
            swap(count[i],count[i+1])
            flag=false;
        }
    }
    return flag;
}
