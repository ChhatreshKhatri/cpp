#include<bits/stdc++.h>
using namespace std;

int main(){
    int
    m1[3][4] = {{1,1,1,1},
                {1,1,1,1},
                {1,1,1,1}},
    m2[4][2] = {{1,2},
                {1,2},
                {1,2},
                {1,2}},
    m3[3][2];
    for(auto &i:m1){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
    for(auto &i:m2){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            m3[i][j]=0;
            for(int k=0;k<4;k++)
                m3[i][j]+=(m1[i][k]*m2[k][j]);
        }
    }
    cout<<"after multiplication"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++)cout<<m3[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}