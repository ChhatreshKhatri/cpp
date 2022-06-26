#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/sum-tree/1
struct Node
{
    int data;
    Node* left, * right;
};
pair<bool,int> isSumTreeFast(Node* root){
        //base case
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL&&root->right==NULL){
            //sigle node or leaf node 
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int> leftAns=isSumTreeFast(root->left);
        pair<bool,int> rightAns=isSumTreeFast(root->right);
        
        bool left=leftAns.first;
        bool right=rightAns.first;
        
        bool condition=root->data==leftAns.second+rightAns.second;
        
        pair<bool,int> ans;
        
        if(left&&right&&condition){
            ans.first=true;
            ans.second=2*root->data;//root->data+rightAns.second+leftAns.second
        
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
int main(){
    

    return 0;
}