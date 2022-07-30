#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        //step 1 swap
        swap(arr[1],arr[size]);
        size--;
        //step 2 heapify
        heapify(arr,size,1);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    int n=(sizeof(arr)/sizeof(arr[0]))-1;
    //heap creation
    for(int i=n/2;i>0;i--) heapify(arr,n,i);
    //print
    cout<<"heap"<<endl;
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    //heap sort
    cout<<"heap sort"<<endl;
    heapSort(arr,n);
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";

    return 0;
}