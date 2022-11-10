#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6]={10,3,3,3,4,4};
    int count=0;
    bool isDistinct=true;
    for(int i=0;i<6;i++){
        for(int j=i-1;j>=0;j--){
            isDistinct=true;
            if(arr[i]==arr[j]){
                isDistinct=false;
                break;
            }
        }
        if(isDistinct==true)count++;
    }
    cout<<count;

    return 0;
}