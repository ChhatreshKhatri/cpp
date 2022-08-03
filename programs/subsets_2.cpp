#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subsets-ii/
void findSubsets(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        ans.push_back(ds);//starting from 0 then incresing at each level/ind
        for(int i=ind;i<nums.size();i++){//TC->O(n)
            if(i!=ind && nums[i]==nums[i-1]) continue;//remove duplicates i.e. not picking the same element after the current index
            ds.push_back(nums[i]);//element to include in subset
            findSubsets(i+1,nums,ds,ans);//increase level/index
            ds.pop_back();//remove the element when its subset is done
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;//SC-> O(2^n * k)
        vector<int> ds;
        sort(nums.begin(),nums.end());
        //sort is important to handel repeating elments and to not repeat subsequence
        findSubsets(0,nums,ds,ans);
        //TC-> O(2^n * n) recursion calls * for loop to store elements
        return ans;
    }
int main(){
    

    return 0;
}