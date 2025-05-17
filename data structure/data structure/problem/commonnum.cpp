/*
结定三个含n(n ≥ 1)个整数的升序数组A、B、C，
请设计一个在时间上尽可能高效的算法，
计算同时存在于这三个数组的元素的个数。
例如A为(1,2,2,3)B为(-1,2,3,5)，C为(-5,0,2,3)，
则输出 2。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 解法1 枚举A 在BC中二分 时间o(nlogn) 空间o(1)
int Bisearch(int arr[], int n, int target){
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]=target)
            return mid;
        else if(arr[mid]<target)
            l=mid+1;
        else
            r=mid-1;
    }
    if(a[l]==target)
        return l;
    else if(a[r]==target)
        return r;
    else
        return -1;
}
int sol1(int A[], int B[], int C[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(Bisearch(B, n, A[i])!=-1 && Bisearch(C, n, A[i])!=-1){
            count++;
            while(i<n-1 && A[i]==A[i+1])
                i++;
        }
    }
    return count;
}

//解法2 三指针 小的往前走 时间O(n)
int sol2(int A[], int B[], int C[], int n){
    int i=0, j=0, k=0;
    int count=0;
    while(i<n && j<n && k<n){
        if(A[i]==B[j] && B[j]==C[k]){
            count++;
            i++;
            j++;
            k++;
            while(i<n-1 && A[i]==A[i+1])
                i++;
            while(j<n-1 && B[j]==B[j+1])
                j++;
            while(k<n-1 && C[k]==C[k+1])
                k++;
        }
        else{
            int m=max(A[i], max(B[j], C[k]));
            if(A[i]<m)
                i++;
            if(B[j]<m)
                j++;
            if(C[k]<m)
                k++;
        }
    }
    return count;
}