#include<bits/stdc++.h>
using namespace std;
//TC-> O(n) SC->O(n+1)dp array + O(n)stack
//recursion to memoization(top-down) answer to base case then come back
int fibo(int n,int dp[]){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}
int fibo2(int n,vector<int> &dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n]=fibo2(n-1,dp)+fibo2(n-2,dp);
}


int main(){
    int n=5;
    int dp[n+1];
    memset(dp,-1,sizeof dp);
    cout<<"memset"<<endl;
    cout<<fibo(n,dp)<<endl;

    cout<<"vector"<<endl;
    int n1=7;
    vector<int> dp2(n1+1,-1);

    cout<<fibo2(n1,dp2)<<endl;

    //recursion to tabulation(bottom-up) base case to required ans
    //TC-> O(n) SC->O(n)
    int m=6;
    vector<int> dp3(m+1,-1);
    dp3[0]=0;
    dp3[1]=1;
    for(int i=2;i<=m;i++){
        dp3[i]=dp3[i-1]+dp3[i-2];
    }
    cout<<"tabulation"<<endl;
    cout<<dp3[m]<<endl;

    //space optimization in tabulation
    //TC->O(n) TC->O(1)3 variables
    cout<<"space optimized"<<endl;
    m=7;
    int prev=1;
    int prev2=0;
    for(int i=2;i<=m;i++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    cout<<prev;

     

    return 0;
}