#include<bits/stdc++.h>
using namespace std;
void sorting(int arr1[],int arr2[],int arr[],int n,int m){
    int i=0;
    int j=0;
    int k=0;
    for(i=0,j=0,k=0;i<n&&j<m;k++){
    if(arr1[i]<arr2[j]){
        arr[k]=arr1[i++];
    }
    else{
        arr[k]=arr2[j++];
        }
    }
    while(i<n){
        arr[k++]=arr1[i++];

    }
    while (j<m)
    {
        arr[k++]=arr2[j++];
    }
    
    return ;
}
int main(){
    int arr1[5]={1,3,5,7,9};
    int arr2[4]={2,4,6,8};
    int arr[9]={0};
    int n=sizeof(arr1)/sizeof(int);
    int m=sizeof(arr2)/sizeof(int);
    sorting(arr1,arr2,arr,n,m);
    for(int i=0;i<9;i++)cout<<arr[i]<<"\t";
    

    return 0;
}