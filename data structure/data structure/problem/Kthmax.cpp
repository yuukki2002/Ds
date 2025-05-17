#include <iostream>
#include <algorithm>

using namespace std;
/*
给定一个包含 N个正整数的集合，请你将它划分为两个集合 A1和 A2，其中 A1
包含 n1个元素，A2包含 n2个元素。集合中可以包含相同元素。
用 S1表示集合 A1内所有元素之和，S2表示集合 A2内所有元素之和。
请你妥善划分，使得 |n1−n2|尽可能小，并在此基础上 |S1−S2|尽可能大。
*/

int parition(int a[], int low, int high){
    int pivot=a[low];
    int i=low-1,j=high+1;
    while(true){
        do{i++;}while(a[i]<pivot);
        do{j++;}while(a[j]>pivot);
        if(i>=j)
            return j;
        swap(a[i],a[j]);
    }
}

void quickselect(int a[],int l, int r, int k){
    if(l>=r)
        return;
    int mid=parition(a,l,r);
    if(mid>=k)
        quickselect(a,l,mid-1,k);
    else
        quickselect(a,mid+1,r,k);
    }

    #include <iostream>
    #include <algorithm>
    using namespace std;
    #define N 100000
    
    int A[N];
    
    void kth_elem(int low,int high, int k){
        int pivot=A[low];
        int i=low,j=high;
        while(i<j){
            while(i<j && A[j]>pivot)    j--;
            A[i]=A[j];
            while(i<j && A[i]<pivot)    i++;
            A[j]=A[i];
        }
        A[i]=pivot;
        
        if(i==k)
            return;
        else if (i>k)
            kth_elem(low,i-1,k);
        else
            kth_elem(i+1,high,k);
    }
    long long Sol(int n){
        kth_elem(0,n-1,n/2);
        long long ans=0;
        for(int i=0;i<n;i++)
            if(i<n/2)
                ans-=A[i];
            else ans+=A[i];
        return ans;
    }
    
    int main(){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>A[i];
        if(n%2==0)
            cout<<"0"<<" "<<Sol(n);
        else 
            cout<<"1"<<" "<<Sol(n);
    }