#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };
    void inOrder(TreeNode<int> *root,vector<int> &bst){
    if(root==NULL)    return ;
    inOrder(root->left,bst);
    bst.push_back(root->data);
    inOrder(root->right,bst);
}
vector<int> mergeBST(vector<int> bst1,vector<int> bst2){
    int i=0,j=0; //bst1 and 2 index
    int k=0;//merged bst index
    vector<int> merged(bst1.size()+bst2.size());
    while(i<bst1.size()&&j<bst2.size()){
        if(bst1[i]<bst2[j])    merged[k++]=bst1[i++];
        else merged[k++]=bst2[j++];
    }
    while(i<bst1.size()){
        merged[k++]=bst1[i++];
    }
    while(j<bst2.size()){
        merged[k++]=bst2[j++];
    }
    return merged;
}
TreeNode<int> *inOrderToBST(int start,int end,vector<int> &arr){
    if(start>end)return NULL;
    int mid=(start+end)/2;
    TreeNode<int> *newRoot=new TreeNode<int>(arr[mid]);
    newRoot->left=inOrderToBST(start,mid-1,arr);
    newRoot->right=inOrderToBST(mid+1,end,arr);
    
    return newRoot;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //store inorder-> 
    vector<int> bst1,bst2;
    inOrder(root1,bst1);    //TC->O(n)  SC->O(n)
    inOrder(root2,bst2);    //TC->(m)   SC->O(m)
    //merge inorder
    vector<int> merged=mergeBST(bst1,bst2); //TC->O(n+m) SC->O(n+m)
    //build tree
    int start=0,end=merged.size()-1;
    return inOrderToBST(start,end,merged);  //TC-> O(n+m)
    
}
int main(){
    

    return 0;
}