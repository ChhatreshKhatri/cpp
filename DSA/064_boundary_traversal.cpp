#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *buildTree(Node *root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for inserting in left" << endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in left" << endl;
    root->right = buildTree(root->right);

    return root;
}
void traverseLeft(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}
void traverseLeaf(Node *root, vector<int> &ans)
{
    // base
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    // after these calls
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);

    // left part print or store
    traverseLeft(root->left, ans);

    // traverse leaf nodes
    // leaf subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right
    traverseRight(root->right, ans);

    return ans;
}
int main()
{
    Node *root = NULL;
    buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 -1
    cout << "boundary traversal: ";
    vector<int> v = boundary(root);
    for (int i : v)
        cout << i << " ";

    return 0;
}