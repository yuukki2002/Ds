#include <iostream>
#include <algorithm>

using namespace std;

/*
给定一个含n(n≥1)个整数的数组A，
记连续子数组A[i:j](0≤i≤j<n)的元素和Sum(A[i:j])= A[]+ A[i+1]+…+A[]。
请设计一个在时间上尽可能高效的算法，计算所有连续子数组的元素和的最大值
*/

int sol(int A[], int n){
    int d=A[0],ans=A[0];
    for(int i=1;i<n;i++){
        d=max(d,d+A[i]);
        ans=max(ans,d);
    }
    return ans;
}