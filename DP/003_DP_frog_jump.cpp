#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

//recursion
int func(int ind,vector<int> &heights){
    if(ind==0)return 0;
    int left=func(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)right=func(ind-1,heights)+abs(heights[ind]-heights[ind-2]);
    return min(left,right);
}

//memoization
int func(int ind,vector<int> &heights,vector<int> &dp){
    if(ind == 0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=func(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)right=func(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    
    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return func(n-1,heights,dp);
}

//tabulation
int frogJump2(int n,vector<int> &heights){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    //first step, second step
    for(int i=1;i<n-1;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=dp[i-2]+abs(heights[i]-heights[i-2]);

        dp[i]=min(fs,ss);
    }
    cout<<dp[n];
    return 0;
}

//space optimization
int frogJump3(int n,vector<int> &heights){
    int prev1i=0;
    int prev2i=0;
    //first step, second step
    for(int i=1;i<n-1;i++){
        int fs=prev1i+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=prev2i+abs(heights[i]-heights[i-2]);
        int curri=min(fs,ss);
        prev2i=prev1i;
        prev1i=curri;
    }
    cout<<prev1i;
    return 0;
}

int main(){
    

    return 0;
}