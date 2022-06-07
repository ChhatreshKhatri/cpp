#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="12034518012831028912938102390813";
    int i=0;
    int a[10]={0};
    while(str[i]!='\0'){
        a[str[i]-48]++;//str[i]=1    0=48 in ascii    so  we subtract 48 to get int
        i++;
    }
    for(i=0;i<10;i++)cout<<i<<"\t"<<a[i]<<endl;

    return 0;
}