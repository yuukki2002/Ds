/*
给定三个含n(n≥1)个整数的数组A、B、C，请设计一个在时间上尽可能高效的算法，统计满足Ai < B[]<C[k]的三元组(i,j,k)的数量。要求:
(1)给出算法的基本设计思想。"
(2)根据设计思想，采用C 或 C++语言描述算法，关键之处给出注释。
(3)说明你所设计算法的平均时间复杂度和空间复杂度。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Bisearch(vector<int> &a, int x){
    int l=0, r=a.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return l;
}// 返回第一个大于等于x的下标


// 返回第一个大于x的下标
/*
int Bisearch(vector<int> &a, int x){
    int l=0, r=a.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]<=x) l=mid+1;
        else r=mid-1;
    }
    return l;
}返回
*/
int countTriple(vector<int> &a, vector<int> &b, vector<int> &c){
    int n=a.size();
    int m=b.size();
    int l=c.size();
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    int count=0;
    for(int i=0;i<m;i++){
        int l1=Bisearch(a, b[i]);
        int l2=Bisearch(c, b[i]);
        count+=l1*(l-l2);
    }
    return count;
}