#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode{
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
void inOrderTraversal(BinaryTreeNode<int> *root,int &count){
    //base case
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left,count);
    //leat node
    if(root->left==NULL&&root->right==NULL){
        count++;
    }
    inOrderTraversal(root->right,count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    inOrderTraversal(root,cnt);
    return cnt;
}
int main(){

    return 0;
}