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
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0; // to initialize it as zero
    recurPermute(ds, nums, ans, freq);
    // TC-> O(n*n!) SC->O(n)+O(n) (ds + freq)
    return ans;
}

// 2nd
//TC->O() SC->O()

int main()
{

    return 0;
}