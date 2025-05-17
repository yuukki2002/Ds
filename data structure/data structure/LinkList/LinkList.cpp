#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

/*
01，在带头结点的单链表工中，删除所有值为x的结点，
并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。
时间复杂度O(n)，空间复杂度O(1)
*/
bool Deletex(Node *L, int x){
    if(L==NULL || L->next==NULL)
        return false;
    Node *p=L, *q=p->next;
    while(q!=NULL){
        if(q->data==x){
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return true;
}

/*
02.试编写在带头结点的单链表工中删除一个最小值结点的高效算法(假设该结点唯一).
*/
bool DeleteMin(Node *L){
    int min=0x7fffffff;
    if(L==NULL || L->next==NULL)
        return false;
    Node *p=L,*q=L->next;
    Node *minNode, *minNodePrev;
    while(q!=NULL){
        if(q->data<min){
            min=q->data;
            minNode=q;
            minNodePrev=p;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    minNodePrev->next=minNode->next;
    free(minNode);
    return true;
}

/*
03、试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为0(1).
*/
bool Reverse(Node *L){
    if(L==NULL || L->next==NULL)
        return false;
    Node *p=L->next;
    while(p!=NULL){
        Node *q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
    return true;
}

bool Reverse_2(Node *L){
    if(L==NULL || L->next==NULL)
        return false;
    Node *pre,*p=L->next, *r=p->next;
    while(r!=NULL){
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;
    }
    L->next=p;
    return true;
}

/*
辅助空间复杂度为 0(1).
04、设在一个带表头结点的单链表中，所有结点的元素值无序，试编写一个函数，删除表中
所有处于给定的两个值(作为函数参数给出)之间的元素(若存在)。
*/

bool DeleteBetweenXandY(Node *L, int x, int y){
    if(L==NULL || L->next==NULL)
        return false;
    Node *p=L, *q=p->next;
    while(q!=NULL){
        if(q->data>x && q->data<y){
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return true;
}

/*
05.给定两个单链表，试分析找出两个链表的公共结点的思想(不用写代码).
*/

/*
由于两个链表有公共节点代表从某一节点开始后续节点相同
1. 先遍历两个链表，分别计算出两个链表的长度len1和len2
2. 计算出两个链表的长度差值d=abs(len1-len2)
3. 让长的链表先走d步
4. 然后两个链表同时走，直到相遇
5. 如果相遇，则返回相遇的结点，否则返回NULL
*/


/*
06.设 C={a1,b1,a2,b2,…,an,bn}为线性表，采用带头结点的单链表存放，设计一个就地算
法，将其拆分为两个线性表，使得A={a1,a2,…,an}，B={b1.…,b2,bn}.
*/

bool Split(Node *L, Node &A, Node &B){
    if(L==NULL || L->next==NULL)
        return false;
    Node *p=(Node*)malloc(sizeof(Node)),*rear;    //B头节点
    p->next=NULL;
    rear=p;
    Node *q=L->next, r=q->next;
    while(r!=NULL){
        q->next=r->next;
        r->next=NULL;
        rear->next=r;
        rear=rear->next;
        q=q->next;
        r=q->next;
    }
    A=L;
    B=p;
    return true;
}