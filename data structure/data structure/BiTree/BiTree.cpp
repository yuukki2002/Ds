#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 基本操作
void Preorder(BiTree T){
    if(T==NULL)
        return;
    cout<<T->data<<" ";
    Preorder(T->lchild);
    Preorder(T->rchild);
}

void Inorder(BiTree T){
    if(T==NULL)
        return;
    Inorder(T->lchild);
    cout<<T->data<<" ";
    Inorder(T->rchild);
}

void Postorder(BiTree T){
    if(T==NULL)
        return;
    Postorder(T->lchild);
    Postorder(T->rchild);
    cout<<T->data<<" ";
}

void LevelOrder(BiTree T){
    if(T==NULL)
        return;
    vector<BiTNode*> queue;
    queue.push_back(T);
    while(!queue.empty()){
        BiTNode* node = queue.front();
        queue.erase(queue.begin());
        cout<<node->data<<" ";
        if(node->lchild)
            queue.push_back(node->lchild);
        if(node->rchild)
            queue.push_back(node->rchild);
    }
}

//非递归中序遍历

void InOrder_(BiTree T){
    if(T==NULL)
        return;
    vector<BiTNode*> stack;
    BiTNode *p=T;
    while(!stack.empty()||p!=NULL){
        if(p!=NULL){
            stack.push_back(p);
            p=p->lchild;
        }
        else{
            p=stack.back();
            stack.pop_back();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

// 非递归先序遍历
void PreOrder_(BiTree T){
    if(T==NULL)
        return;
    vector<BiTNode*> stack;
    BiTNode *p=T;
    while(!stack.empty()||p!=NULL){
        if(p!=NULL){
            cout<<p->data<<" ";
            stack.push_back(p);
            p=p->lchild;
        }
        else{
            p=stack.back();
            stack.pop_back();
            p=p->rchild;
        }
    }
}