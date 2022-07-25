#include <bits/stdc++.h>
using namespace std;
int bSFirstOccurance(vector<int> &nums, int e, int target)
{
    int s = 0;
    e = e - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        cout << "start " << s << " "
             << "mid " << mid << " "
             << "end " << e << endl;
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (target > nums[mid])
        {
            /// right part
            s = mid + 1;
        }
        else if (target < nums[mid])
        {
            // left part
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    cout << "ans " << ans << endl;
    return ans;
}
int bSLastOccurance(vector<int> &nums, int e, int target)
{
    int s = 0;
    e=e-1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        cout << "start " << s << " "
             << "mid " << mid << " "
             << "end " << e << endl;
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (target > nums[mid])
        {
            /// right part
            s = mid + 1;
        }
        else if (target < nums[mid])
        {
            // left part
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
// vector<int> searchRange(vector<int>& nums, int target) {
//         int size=nums.size();
//         int i=0;
//         int mid=size/2;
//         vector<int> ans;

//     }
int main()
{
    vector<int> v = {1, 1, 1, 1, 1, 2, 3, 3, 5};
    int size = v.size();

    int ans = bSFirstOccurance(v, size, 1);
    cout << "first " << ans << endl;
    ans = bSLastOccurance(v, size, 1);
    cout << "last " << ans << endl;

    return 0;
}