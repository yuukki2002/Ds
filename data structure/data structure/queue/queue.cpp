#include <iostream>
using namespace std;
#define MaxSize 100
#define ElemType int
// 顺序结构队列

typedef struct {
    int data[MaxSize];
    int front, rear;
} Queue;

void InitQueue(Queue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(Queue Q, ElemType x){
    if((Q.rear + 1) == MaxSize){
        cout << "Queue overflow" << endl;
        return false;
    }
    Q.data[Q.rear++] = x;
    return true;
}

bool DeQueue(Queue Q, ElemType &x){
    if(Q.front == Q.rear){
        cout << "Queue Empty" << endl;
        return false;
    }
    x = Q.data[Q.front++];
    return true;
}