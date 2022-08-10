#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *numsToBST(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = numsToBST(nums, start, mid - 1);
    root->right = numsToBST(nums, mid + 1, end);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int end = nums.size();
    return numsToBST(nums, 0, end - 1);
}
int main()
{

    return 0;
}