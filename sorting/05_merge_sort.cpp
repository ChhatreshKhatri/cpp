#include<bits/stdc++.h>
using namespace std;
//tc->nlogn
//sc-> O(n)
void mergeUtil(int arr[],int start,int end){
    int mid=start+(end-start)/2;

    int left=mid-start+1;
    int right=end-mid;

    //create 2 halfs of the array
    int *leftArray=new int[left];
    int *rightArray=new int[right];

    //assign values in two half arrays
    int index=start;
    for(int i=0;i<left;i++)leftArray[i]=arr[index++];
    // for(int i=0;i<left;i++)cout<<leftArray[i]<<" ";cout<<endl;
    // index=mid+1;
    for(int i=0;i<right;i++)rightArray[i]=arr[index++];
    // for(int i=0;i<right;i++)cout<<rightArray[i]<<" ";cout<<endl;
    //merge 2 sorted array
     int index1=0;//left array
     int index2=0;//right array
     index=start;//main array

     while(index1 < left && index2 < right){
        if(leftArray[index1] < rightArray[index2]){
            arr[index++] = leftArray[index1++];
        }
        else{
            arr[index++] = rightArray[index2++];
        }
     }
     while(index1<left){
        arr[index++]=leftArray[index1++];
     }
     while(index2<right){
        arr[index++]=rightArray[index2++];
     }
     //free space at the end
     delete []rightArray;
     delete []leftArray;
}
void mergeSort(int arr[],int start,int end){
    //base case
    if(start>=end)return;

    //divide the array
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    //merge the divided array
    mergeUtil(arr,start,end);
}
int main(){
    int a[] = { 4, 5, 3, 2, 4, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    for(auto i:a)cout<<i<<" ";cout<<endl;
    mergeSort(a,0,n-1);
    for(auto i:a)cout<<i<<" ";cout<<endl;


    return 0;
}