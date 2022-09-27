#include<bits/stdc++.h>
using namespace std;
// unstable means 5 5` to 5` 5 after sorting
/*
Selection sort works by finding the minimum element and then inserting it in its correct position by swapping with the element which is in the position of this minimum element. This is what makes it unstable.
*/
/*
SPACE COMPLEXITY->O(1)
TIME COMPLEXITY-> 
worst best average-> O(n^2)
*/
int main(){
    int arr[6]={2,5,3,6,1,4};
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    int n=6;
    //selection sort
    for(int i=0;i<n-1;i++){
        int index=i;
        for(int j=i+1;j<n;j++){
            if(arr[index]>arr[j]){
                index=j;
            }
        }
        if(index!=i){
            int temp=arr[index];
            arr[index]=arr[i];
            arr[i]=temp;
        }
    }
    for(auto i: arr)cout<<i<<" ";cout<<endl;

    //reverse condition
    //if(arr[index] < arr[j])
    return 0;
}