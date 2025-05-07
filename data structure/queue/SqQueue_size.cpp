#include <iostream>
using namespace std;
#define MaxSize 100
#define ElemType int

// 循环队列 使用size存储队列长度
typedef struct {
    ElemType data[MaxSize];
    int front, rear, size;
} SqQueue_size;

void InitQueue(SqQueue_size &Q) {
    Q.front = Q.rear = 0;
    Q.size = 0;
}

bool EnQueue(SqQueue_size &Q, ElemType x){
    if(Q.size == MaxSize){
        cout << "Queue overflow" << endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.size++;
    return true;
}

bool DeQueue(SqQueue_size &Q, ElemType &x){
    if(Q.size == 0){ // if(Q.front == Q.rear)
        cout << "Queue Empty" << endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}