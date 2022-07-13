#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    int solve(BinaryTreeNode<int>* root,int &i, int k){
    //base case
    if(root==NULL)return -1;
    //left
    int left=solve(root->left,i,k);
    if(left!=-1)return left;
    //node
    i++;
    if(i==k)return root->data;
    //right
    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    return solve(root,i,k);
}
int main(){
    

    return 0;
}