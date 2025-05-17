#include<iostream>
#include<algorithm>
#include<vector>   
using namespace std;
#define N 1000

void InsertSort(int A[], int n){
    int i,j;
    for(i=1;i<n;i++){
        A[0]=A[i];
        if(A[i]<A[i-1]){
            for(j=i-1;j>0&& A[j]>A[0];j--)
                A[j+1]=A[j];
            A[j+1]=A[0];
        }
    }
}

void Bi_InsertSort(int A[],int n){
    int i,j,low,high,mid;
    for(int i=1;i<n;i++){
        A[0]=A[i];
        low=1, high=i-1;
        while(low<=high){
            mid=(low+high)>>1;
            if(A[mid]>A[0])
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=low;j--)
            A[j+1]=A[j];
        A[low]=A[0];
    }
}

void BubbleSort(int A[], int n){
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=0;j<n-1-i;j++)
            if(A[j]>A[j+1]){
                swap(A[j], A[j+1]);
                flag=true;
            }
        if(!flag)
            break;
    }
}

int Partition(int A[], int low, int high){
    int pivot=A[low];
    while(low<high){
        while(low<=high && A[high]>pivot)
            high--;
        A[low]=A[high];
        while(low<=high && A[low]<pivot)
            low++;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void QuickSort(int A[],int low, int high){
    if(low<high){
        int pivot=Partition(A, low, high);
        QuickSort(A, low, pivot-1);
        QuickSort(A, pivot+1, high);
    }
}

void SelectSort(int A[], int n){
    int i,j;
    for(i=0;i<n;i++){
        int index=i;
        for(j=i+1;j<n;j++)
            if(A[j]<A[index]){
                index=j;
            }
        swap(A[i], A[j]);
    }
}

void HeapAdjust(int A[], int k, int len){
    A[0]=A[k];
    for(int i=2*k;i<len;i++){
        if(i<len && A[i]<A[i+1])
            i++;
        if(A[0]>=A[i])  break;  //大根堆
        else{
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}

void BuildMaxHeap(int A[], int len){
    for(int i=len/2;i>0;i--)
        HeapAdjust(A,i,len);
}

void HeapSort(int A[], int len){
    BuildMaxHeap(A,len);
    for(int i=len;i>1;i--){
        cout<<A[i]<<" ";
        swap(A[1], A[i]);
        HeapAdjust(A,1,i-1);
    }
}

void MergeSort(int low, int high, int A[]){
    if(low<high){
        int mid=(low+high)>>1;
        MergeSort(low, mid, A);
        MergeSort(mid+1, high, A);
        Merge(low, mid, high, A);
    }
}

int B[N];
void Merge(int low, int mid, int high, int A[]){
    for(int i=low;i<high;i++)
        B[i]=A[i];
    int i,j,k;
    for(i=low, j=mid, k=low;i<mid&&j<high;k++){
        if(B[i]<B[j])
            A[k]=B[i++];
        else    
            A[k]=B[j++];
    }
    while(i<mid)
        A[k++]=B[i++];
    while(j<high)
        A[k++]=B[j++];
}


/*
int main(){
    int A[]={0,3,2,4,5,6,98,8,9};
    InsertSort(A, 9);
    for(int i=1;i<9;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
*/