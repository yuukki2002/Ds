#include <iostream>
using namespace std;
#define ElemType int
// 链式存储结构的栈

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkStack;

void InitStack(LinkStack &s) {
    s = (LinkStack)malloc(sizeof(LNode));
    s->next = NULL;
}

bool StackEmpty(LinkStack s) {
    return s->next == NULL;
}

bool Push(LinkStack &s,ElemType x){
    LNode  * p = (LinkStack)malloc(sizeof(LNode));
    p->data = x;
    p->next = s->next;
    s->next = p;
    return true;
}

bool Pop(LinkStack &s, ElemType &x){
    if(s->next == NULL){
        cout << "Stack Empty" << endl;
        return false;
    }
    LNode *p = s->next;
    x = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetTop(LinkStack s, ElemType &x){
    if(s->next == NULL){
        cout << "Stack Empty" << endl;
        return false;
    }
    x = s->next->data;
    return true;
}

