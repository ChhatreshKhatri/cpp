#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/level-order-traversal_796002
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include <queue>
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    queue<BinaryTreeNode<int> *> pn;
    pn.push(root);
    while (!pn.empty())
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        cout << front->data << ":";
        if (front->left)
        {
            pn.push(front->left);
            cout << "L:" << front->left->data;
        }
        else
        {
            cout << "L:-1";
        }
        cout << ",";

        if (front->right)
        {
            pn.push(front->right);
            cout << "R:" << front->right->data << endl;
        }
        else
        {
            cout << "R:-1" << endl;
        }
    }
}
int main()
{

    return 0;
}