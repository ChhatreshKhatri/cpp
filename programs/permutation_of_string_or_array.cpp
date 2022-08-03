#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/permutations/
//1st
//TC-> O(n*n!) SC->O(n)+O(n) (ds + freq)
void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    // base
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];//000 pick or not pick the index->extra space
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0; // to initialize it as zero
    recurPermute(ds, nums, ans, freq);
    // TC-> O(n*n!) SC->O(n)+O(n) (ds + freq)
    return ans;
}

// 2nd
//TC->O(n*n!) n for element store n! for recursion SC->O(n) recursion space and n! for ans
void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);//swap
            recurPermute(index+1,nums,ans);//next state
            swap(nums[index],nums[i]);//reswap/ back tracked
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
        
        return ans;
    }
int main()
{

    return 0;
}