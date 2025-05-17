/*
给定一个含n(n>1)个正整数的数组A，
以及一个正整数k，
请设计一个在时间上尽可能高效的算法，
计算满足元素和sum>=k的连续子数组中的最小长度。
如果不存在满足条件的子数组，则返回0。
如:A为(1,2,2,1)，k=4，(2,2)为满足条件的长度最小的连续子数组，则输出其长度 2。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MinLength(int A[], int n, int k){
    int i=0, j=0;
    int sum=0;
    int minlen=n+1;
    while(j<n){
        sum+=A[j];
        while(sum>=k){
            minlen=min(minlen, j-i+1);
            sum-=A[i++];
        }
        j++;
    }
    return minlen==n+1?0:minlen;
}

int main(){
    int A[]={1,2,2,1};
    int k=4;
    cout<<MinLength(A, 4, 4)<<endl; // 输出 2
    return 0;
}