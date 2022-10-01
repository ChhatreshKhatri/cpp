#include<bits/stdc++.h>
using namespace std;
int Partition(int arr[],int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)cnt++;
    }

    //place pivot at right position
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);

    //left and right part of pivot
    int i=s,j=e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;

        if(i < pivotIndex && j > pivotIndex) swap(arr[i++],arr[j--]);
    }

    return pivotIndex;
}
void quickSort(int arr[],int s,int e){
    if(s>=e)return;
    
    int p=Partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main(){
    int arr[6]={2,5,3,6,1,4};
    int n=6;
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    quickSort(arr,0,n-1);
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    return 0;
}