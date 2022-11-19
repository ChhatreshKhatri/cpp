#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4][4]={{1,5,9,13},
                   {2,6,10,14},
                   {3,7,11,15},
                   {4,8,12,16}};
    for(auto &row:arr){
        for(auto col:row)cout<<col<<" ";
        cout<<endl;
    }
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    cout<<endl<<"after transpose"<<endl;
    for(auto &row:arr){
        for(auto col:row)cout<<col<<" ";
        cout<<endl;
    }
    return 0;
}