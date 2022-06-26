#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
bool isIdentical(Node *r1, Node *r2)
    {
        //base case
        if(r1==NULL&&r2==NULL){return true;}
        if(r1==NULL&&r2!=NULL){return false;}
        if(r1!=NULL&&r2==NULL){return false;}
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        
        bool value=r1->data==r2->data;
        if(left&&right&&value){
            return true;
        }
        else{
            return false;
        }
    }

bool isIdentical2(Node *r1, Node *r2)
    {
        //base case
        if(r1==NULL||r2==NULL)return r1==r2;
        return (r1->data==r2->data)&&isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right);
    }
int main(){
    
    

    return 0;
}