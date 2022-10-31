#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=932342;//octal
    cout<<"number= "<<n<<endl;
    while(n>10){
        n/=10;
    }
    cout<<n;

    return 0;
}