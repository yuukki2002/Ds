/*
设平面上两个不同的点p1=(x1,y1)和p2=(x2,y2)，
若x1,≥x2且y1≥y2则称p1支配p2。
给定平面上n(n≥1)个不同点的集合P ={p,p,…,pn-1}，
若某点p,不被P中任意其它点支配，
则称p,为P的极大点。假设数组X、Y分别保存点集的横纵坐标，
即p;=(X[i],Y[i])，假设点集的坐标都是整数。
请设计一个在时间上尽可能高效的算法，计算点集P中极大点的个数。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
思路:对X Y排序 X降序 X相同时按y升序排列
顺序扫描xy 记录最大值maxy 因为x降序 扫描到的y如果大于maxy 则一定是极大点
记录maxy 若遇到更大的y 则更新maxy
时间复杂度O(nlogn) 空间复杂度O(1)
*/

bool compare(int x1, int y1, int x2, int y2){
    if(x1>x2)
        return true;
    else if(x1==x2 && y1>y2)
        return true;
    else return false;
}

void QuickSort(int X[], int Y[], int low, int high){
    if(low>=high)
        return;
    int lowx=X[low],lowy=Y[low];
    int i=low,j=high;
    while(i<j){
        while(i<j && compare(X[j],Y[j],lowx,lowy))
            j--;
        X[i]=X[j], Y[i]=Y[j];
        while(i<j && compare(lowx, lowy, X[i], Y[i]))
            i++;
        X[j]=X[i], Y[j]=Y[i];
    }
    X[i]=lowx, Y[i]=lowy;
    QuickSort(X, Y, low, i-1);
    QuickSort(X, Y, i+1, high);
}

int Sol(int X[], int Y[], int n){
    QuickSort(X, Y, 0, n-1);
    int ans=0;
    int maxy=Y[0];
    for(int i=0;i<n;i++){
        if(Y[i]>maxy){
            ans++;
            maxy=Y[i];
        }
    }
    return ans;
}

int main(){
    int X[]={1,2,3,4};
    int Y[]={4,3,2,1};
    cout<<Sol(X,Y,5)<<endl;
    return 0;
}