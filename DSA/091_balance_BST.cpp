#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
void inOrder(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
TreeNode<int> *inOrderToBST(int s, int e, vector<int> &v)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    TreeNode<int> *root = new TreeNode<int>(v[mid]);
    root->left = inOrderToBST(s, mid - 1, v);
    root->right = inOrderToBST(mid + 1, e, v);

    return root;
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> v;
    inOrder(root, v);
    return inOrderToBST(0, v.size() - 1, v);
}
int main()
{

    return 0;
}