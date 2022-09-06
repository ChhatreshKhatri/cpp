#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// TC-> O(nodes) SC->O(height)
TreeNode *pruneTree(TreeNode *root)
{
    if (root != NULL)
    {
        // post order traversal
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // check if zero and its right and left child exist or not
        if (!root->left && !root->right && root->val == 0)
            return NULL;
    }
    return root;
}
int main()
{

    return 0;
}