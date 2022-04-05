#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i] < nums[i-1]);
                cnt++;
        }
        if(nums[nums.size()-1] > nums[0])
            cnt++;
        
        return cnt<=1;
    }
int main()
{
    vector<int> v={3,4,5,1,2};
    vector<int> v2={1,2,3,5,2,1};
    cout<<check(v)<<endl;
    cout<<check(v2);

return 0;
}