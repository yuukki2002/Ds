#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXSIZE 10000
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 非递归算法求书高

int Height(BiTree T){
    if(T==NULL)
        return 0;
    BiTNode* Queue[MAXSIZE];
    int front=-1,rear=-1;
    int last=0,level=0;
    Queue[++rear]=T;
    while(front<rear){
        BiTNode *p=Queue[++front];
        if(p->lchild!=NULL)
            Queue[++rear]=p->lchild;
        if(p->rchild!=NULL)
            Queue[++rear]=p->rchild;
        if(front==last){
            last=rear;
            level++;
        }
    }
    return level;
}

// 计算双分枝节点个数
int count=0;
void countBranch(BiTree T){
    if(T==NULL)
        return;
    if(T->lchild!=NULL && T->rchild!=NULL)
        count++;
    countBranch(T->lchild);
    countBranch(T->rchild);
}

// 将树B中所有节点左右子树进行交换
void swap_T(BiTree T){
    if(T==NULL)
        return;
    swap_T(T->lchild);
    swap_T(T->rchild);
    swap(T->lchild,T->rchild);
}

// 先序遍历中第k个节点的值
int cnt=0;
void k_Preorder(BiTree T, int k){
    if(T==NULL)
        return;
    cnt++;
    if(cnt==k){
        cout<<T->data<<" "<<endl;
        return;
    }
    k_Preorder(T->lchild,k);
    k_Preorder(T->rchild,k);
}

// k_Preorder(T,k);

// 对于每个值为x的节点 删除以他为根的子树
void DelX(BiTree T, int x){
    if(T==NULL)
        return;
    if(T->data==x){
        DelX(T->lchild, x);
        DelX(T->rchild, x);
        free(T);
        T=NULL;
        return;
    }
    DelX(T->lchild, x);
    DelX(T->rchild, x);
}

// 打印值为x的值的所有祖先

bool AncestorX(BiTree T, int x){
    if(T==NULL)
        return false;
    if(T->data==x)
        return true;

    if(AncestorX(T->lchild, x) || AncestorX(T->rchild, x)){
        cout<<T->data<<" ";
        return true;
    }

    return false;
}

// 寻找p q的最近公共祖先
BiTree LCA(BiTree T, BiTree p, BiTree q){
    if(T==NULL || T==p || T==q)
        return T;
    BiTree left=LCA(T->lchild, p, q);
    BiTree right=LCA(T->rchild, p, q);
    if(left!=NULL && right!=NULL)
        return T;
    return left!=NULL?left:right;
}

//  求非空二叉树的宽度
int Breadth(BiTree T){
    if(T==NULL)
        return 0;
    BiTNode* Queue[MAXSIZE];
    int front=-1,rear=-1;
    int last=0,breadth=1;
    Queue[++rear]=T;
    while(front<rear){
        int level=rear-front;
        breadth=max(breadth, level);
        for(int i=0;i<level;i++){
            BiTNode *p=Queue[++front];
            if(p->lchild!=NULL)
                Queue[++rear]=p->lchild;
            if(p->rchild!=NULL)
                Queue[++rear]=p->rchild;
        }
    }
    return breadth;
}

// 已知满二叉树先序序列pre 求其后序序列post
void PreToPost(int pre[], int preL, int preR, int post[],int postL, int postR){
    if(preL>preR)
        return;
    if(preL==preR){
        post[postR] = pre[preL];
        return;
    }
    else{
        int k=(preR-preL)>>1;
        PreToPost(pre, preL+1, preL+k, post, postL, postL+k-1);
        PreToPost(pre, preL+k+1, preR, post, postL+k, postR-1);
        post[postR] = pre[preL];
    }
}

// 将二叉树叶节点从左到右链接 表头为head
int k=0;
void Collect(BiTree T, BiTree leaf[]){
    if(T==NULL)
        return;
    if(T->lchild==NULL && T->rchild==NULL){
        leaf[k++]=T;
        return;
    }
    Collect(T->lchild, leaf);
    Collect(T->rchild, leaf);
}

void LinkLeaf(BiTree T, BiTree &head){
    if(T==NULL)
        return;
    BiTree leaf[MAXSIZE];
    Collect(T, leaf);
    head = leaf[0];
    BiTree p=head;
    for(int i=1;i<k;i++){
        p->rchild=leaf[i];
        p=p->rchild;
    }
}

// 判断两颗树是否相似
bool IsSimilar(BiTree T1, BiTree T2){
    if(T1==NULL && T2==NULL)
        return true;
    if(T1==NULL || T2==NULL)
        return false;
    return IsSimilar(T1->lchild, T2->lchild) && IsSimilar(T1->rchild, T2->rchild);
}

// 计算树的WPL
int WPL(BiTree T, int d){
    if(T==NULL)
        return 0;
    if(T->lchild==NULL && T->rchild==NULL)  // 仅叶节点参与计算
        return d* T->data + WPL(T->lchild, d+1) + WPL(T->rchild, d+1);
}

// WPL(T,1)

// 统计二叉树中度为0/1/2的节点个数
int count_=0;
void CountDegree(BiTree T){
    if(T==NULL)
        return;
    if(T->lchild==NULL && T->rchild==NULL)
    // if(T->lchild!=NULL && T->rchild!=NULL)
    // if(T->lchild!=NULL && T->rchild==NULL || T->lchild==NULL && T->rchild!=NULL) 
        count_++;
    CountDegree(T->lchild);
    CountDegree(T->rchild);
}

// 删除所有叶节点
void DelLeaf(BiTree &T){
    if(T==NULL)
        return;
    if(T->lchild==NULL && T->rchild==NULL){
        free(T);
        T=NULL;
        return;
    }
    DelLeaf(T->lchild);
    DelLeaf(T->rchild);
}

// 指定p所在的层次
int Level(BiTree T, BiTree p){
    return Height(T)-Height(p)+1;
}

// 计算二叉树中节点最大的值
int MaxValue(BiTree T){
    if(T==NULL)
        return INT_MIN; //防止负数出现
    int max1=T->data;
    int max2=MaxValue(T->lchild);
    int max3=MaxValue(T->rchild);
    return max(max1, max(max2, max3));
}

// 先序输出节点值及层次
void PreOrder_level(BiTree T, int d){
    if(T==NULL)
        return;
    cout<<T->data<<" "<<d<<endl;
    PreOrder_level(T->lchild, d+1);
    PreOrder_level(T->rchild, d+1);
}
//PreOrder_level(T, 1);

// 输入整数 输出路径以及与data相等的所有路径
/*
      10
    5  12
   4  7
输入22 输出10 12和10 5 7
*/
void PrintPath(BiTree T, int target, vector<int>& path) {
    if (T == NULL) return;

    path.push_back(T->data);
    
    if (T->lchild == NULL && T->rchild == NULL && target == T->data) {
        for (int val : path)
            cout << val << " ";
        cout << endl;
    }

    PrintPath(T->lchild, target - T->data, path);
    PrintPath(T->rchild, target - T->data, path);

    path.pop_back(); // 回溯
}
