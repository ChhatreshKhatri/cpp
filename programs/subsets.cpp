#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subsets/submissions/

// 1st
vector<vector<int>> func(vector<int> &nums, int i)
{
    // base
    if (i >= nums.size())
        return {{}};
    vector<vector<int>> partialAns = func(nums, i + 1);
    vector<vector<int>> ans;
    for (auto x : partialAns)
        ans.push_back(x);

    for (auto x : partialAns)
    {
        x.push_back(nums[i]);
        ans.push_back(x);
    }
    return ans;
}
vector<vector<int>> subsets(vector<int> &nums)
{
    return func(nums, 0);
}

// 2nd in sequence
//TC-> GP progression 2^n-1->2^n
//SC-> O(n+1) O(n) tree height space compexity
void func(vector<int> &nums, int i, vector<int> &subsets, vector<vector<int>> &ans)
{
    // base
    if (i == nums.size())
    {
        ans.push_back(subsets);
        return;
    }
    // include the ith element i.e 1 then 2 then 3
    subsets.push_back(nums[i]);
    func(nums, i + 1, subsets, ans);
    // do not include the ith element and process without it
    subsets.pop_back();
    func(nums, i + 1, subsets, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> subset;
    func(nums, 0, subset, ans);

    return ans;
}
int main()
{

    return 0;
}