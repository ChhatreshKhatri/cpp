#include<bits/stdc++.h>
using namespace std;
template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };
    pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp=root;
    int pre=-1;
    int suc=-1;
    //find key
    
    while(temp->data!=key){
        if(temp->data>key){
            suc=temp->data;
            temp=temp->left;            
        }
        else{
            pre=temp->data;
            temp=temp->right;            
        }
    }
    //pre and suc
    BinaryTreeNode<int>* leftTree=temp->left;
    while(leftTree!=NULL){
        pre=leftTree->data;
        leftTree=leftTree->right;
    }
    //succ
    BinaryTreeNode<int>* rightTree=temp->right;
    while(rightTree!=NULL){
        suc=rightTree->data;
        rightTree=rightTree->left;
    }
    // pair<int,int> ans=make_pair(pre,suc);
    // return ans;
    return {pre,suc};
}
int main(){
    

    return 0;
}