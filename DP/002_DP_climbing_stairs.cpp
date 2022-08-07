#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/climbing-stairs/
//same as fibonacci
 int climbStairs(int n) {
    int prev1=1;
    int prev2=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    }
int main(){
    int n=10;
    cout<<climbStairs(n);

    return 0;
}