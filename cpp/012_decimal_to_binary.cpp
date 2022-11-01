#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,base=1,ans=0;
    vector<int> ans2;
    cin>>n;
    while(n>0){
        // ans=10*ans+n%2;//can't store once digit 0
        ans2.push_back(n%2);
        n/=2;
    }
    // cout<<ans;
    reverse(ans2.begin(),ans2.end());
    for(auto i:ans2)cout<<i;

    return 0;
}