#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode {
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
void inOrder(BinaryTreeNode<int> *root,vector<int> &in){
    if(root==NULL)return ;
    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inOrderVal;
    inOrder(root,inOrderVal);
    int i=0,j=inOrderVal.size()-1;
    
    while(i<j){
        int sum=inOrderVal[i]+inOrderVal[j];
        if(sum==target)return true;
        else if(sum>target)j--;
        else i++;
    }
    return false;
}
int main(){
    

    return 0;
}