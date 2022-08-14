#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start++], nums[end--]);
    }
}
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    int r = k % n;
    if(r==1)return;
    for(auto i:nums)cout<<i<<" ";cout<<endl;
    reverse(nums, 0, n - 1);
    for(auto i:nums)cout<<i<<" ";cout<<endl;
    reverse(nums, 0, k-1);
    for(auto i:nums)cout<<i<<" ";cout<<endl;
    reverse(nums, k, n - 1);
    for(auto i:nums)cout<<i<<" ";cout<<endl;
}
int main()
{
    vector<int> v = {-1,-2}; /// 3 99 -1 -100
    // ans [100,101,-1,-100,3,99]
    int k = 3;
    
    rotate(v, k);
    cout << endl;
    for (auto i : v)
        cout << i << " ";

    return 0;
}