#include<bits/stdc++.h>
using namespace std;
//recursion 
//TC-> O(2^n) SC-> O(n) recursion stack
int f(int ind,vector<int> &nums){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    
    int pick=nums[ind]+f(ind-2,nums);
    int notpick=0+f(ind-1,nums);    
    return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return f(n-1,nums);
}

//memoisation
//TC->O(n) SC->O(n)+O(n)
int f(int ind,vector<int> &nums,vector<int> &dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    
    int pick=nums[ind]+f(ind-2,nums,dp);
    int notpick=0+f(ind-1,nums,dp);    
    return dp[ind]=max(pick,notpick);
}
int maximumNonAdjacentSum2(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}

//tabulation
//TC->O(n) SC->O(n)
int maximumNonAdjacentSum3(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=dp[i-2];
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[n-1];
}

//space optimization
//TC->O(n) SC->O(1)
int maximumNonAdjacentSum4(vector<int> &nums){
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<nums.size();i++){
        int pick=nums[i];//pick i and pick i-2 only if i>1
        if(i>1) pick+=prev2;// to avoid 0-2=-2 and 1-2=-1
        int notpick=0+prev;
        int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int main(){
    vector<int> v={2,1,4,9};
    cout<<maximumNonAdjacentSum3(v)<<endl;
    cout<<maximumNonAdjacentSum4(v)<<endl;

    return 0;
}