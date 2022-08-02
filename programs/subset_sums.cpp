//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
//TC-> O(2^n) recursion + 
//SC-> O(2^nLog(2^n))
//2^n is size for ans and log(2^n) is sorting an array
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void func(int ind,int sum,vector<int> &arr,int n,vector<int> &sumSubset){
        if(ind==n){
            sumSubset.push_back(sum);
            return;
        }
        //pick element
        func(ind+1,sum+arr[ind],arr,n,sumSubset);
        //not picking element
        func(ind+1,sum,arr,n,sumSubset);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset;
        func(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
