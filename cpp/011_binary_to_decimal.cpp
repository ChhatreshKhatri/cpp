#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,base=1,ans=0,modu=0;
    cin>>n;
    while(n>0){
        modu=n%10;
        ans+=(base*modu);
        n/=10;
        base*=2;
    }
    cout<<ans;

    return 0;
}