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
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorder;
    inOrder(root, inorder);
    int size = inorder.size();
    TreeNode<int> *newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int> *curr = newRoot;
    for (int i = 1; i < size; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    // last node
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
int main()
{

    return 0;
}