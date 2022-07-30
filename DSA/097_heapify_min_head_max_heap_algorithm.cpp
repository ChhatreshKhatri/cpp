#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr,int n,int i){
    int smallest=i;
    //zero based indexing
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)heapify(arr,n,i);
    return arr;
}

void heapifyMaxHeap(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapifyMaxHeap(arr,n,largest);
    }
}

int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=sizeof(arr)/sizeof(arr[0])-1;
    cout<<"before heapify"<<endl;
    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=n/2;i>0;i--){//TC-> O(n)
        heapifyMaxHeap(arr,n,i);
    }
    cout<<"after heapify "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}