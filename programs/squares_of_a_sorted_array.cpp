#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr(nums.size());
        int j2=arr.size()-1;       
        int i=0,j=nums.size()-1;
        while(i<j){
            if(abs(nums[j])>abs(nums[i])){
                arr[j2]=nums[j]*nums[j--];
            }
            else if(abs(nums[i])>=abs(nums[j])){
                arr[j2]=nums[i]*nums[i++];
            }
            j2--;
        }
        arr[0]=nums[i]*nums[i];
        return arr;
    }
int main()
{
    // vector<int> v = {-4, -1, 0, 3, 10};
    vector<int> v = {-7,-3,2,3,11};
    vector<int> ans = sortedSquares(v);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}