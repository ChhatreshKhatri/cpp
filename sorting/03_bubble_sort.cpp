#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[7]={5,3,6,7,2,4,1};
    int n=7;
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    for(int i=0;i<n-1;i++){
        int flag=false;// to stop loop if array sorted
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j]; 
                arr[j]=temp;
                flag=true;
            }
        }
        if(flag==false)break;
    }
    for(auto i:arr)cout<<i<<" ";cout<<endl;

    return 0;
}
//in second loop int j=0;j<n-i-1;j++ is done becasue largest element will be at its correct position