#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[7]={6,3,5,7,2,4,1};
    int n=7;
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    for(int i=1;i<n;i++){
        int j=i-1;
        int value=arr[i];
        while(j>=0 && arr[j]>value){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=value;
    }
    for(auto i:arr)cout<<i<<" ";cout<<endl;

    return 0;
}
//descending order 
// while(j>=0 && arr[j] < value)