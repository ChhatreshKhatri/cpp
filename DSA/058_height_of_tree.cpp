#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int height(struct Node* node){
        // base case
        if(node==NULL)return 0;
        int left=height(node->left);
        int right=height(node->right);
        int ans=max(left,right)+1;
        return ans;
    }
int main(){
    

    return 0;
}