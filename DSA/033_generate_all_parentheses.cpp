#include<bits/stdc++.h>
using namespace std;

vector<string> s;
void rec(int open,int close,string k,int n,vector<string>&ans){
    if(k.length()==2*n){
        ans.push_back(k);
    }
    else{
        if(open<n)rec(open+1,close,k+"(",n,ans);
        if(close<open)rec(open,close+1,k+")",n,ans);
    }
    return ;
}
vector<string> validParenthesis(int n){
    vector<string> ans;
    int open=0,close=0;
    rec(open,close,"",n,ans);
	return ans;
}
int main()
{
    vector<string> s;
    int n=3;
    s=validParenthesis(n);
    // for(auto x: s){
    //     for(int i=0;i<x.length();i++){
    //         cout<<s[i]<<endl;
    //     }
    // }
    for(int i=0;i<s.size();i++)cout<<s[i]<<endl;

return 0;
}