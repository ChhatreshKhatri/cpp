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
//recursion
void printLevel(BinaryTreeNode<int> *node,int level){
    if(node==NULL)return;
    if(level==0)cout<<node->data<<" ";
    else if(level>0){
        printLevel(node->left,level-1);
        printLevel(node->right,level-1);
    }
}
//using queue
void printLevelOrder(BinaryTreeNode<int>* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<BinaryTreeNode<int>*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        BinaryTreeNode<int>* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main()
{
    BinaryTreeNode<int> *node=new BinaryTreeNode(10);
    node->left=new BinaryTreeNode(20);
    node->right=new BinaryTreeNode(30);
    node->left->left=new BinaryTreeNode(40);
    node->left->right=new BinaryTreeNode(50);
    node->left->left->left=new BinaryTreeNode(60);

    cout<<"with height"<<endl;
    //with height 
    // TC-> O(n^2) SC->O(n) n is nbo. of nodes in tree
    //3 is height of tree
    for(int i=0;i<=3;i++)printLevel(node,i);
    cout<<endl<<endl;

    //wiithout height
    printLevelOrder(node);
    cout<<endl<<endl;
    cout<<"without height"<<endl;
    printLevelWise(node);
    return 0;
}