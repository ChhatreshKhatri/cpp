#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right=NULL;
    }
};
Node *buildTree(Node *root){
    int data;
    cout<<"enter data for node"<<endl;
    cin>>data;
    if(root==NULL){
        root=new Node(data);
    }
    if(data==-1)return NULL;

    cout<<"enter data to insert left of "<<root->data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data to insert right of "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        //important to remove the node from queue when it is being processed and let other node get in front
        if(temp==NULL){
            //either root is NULL or the previous level is completed
            cout<<endl;
            if(!q.empty())q.push(NULL);//queue has some node left
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
int height(struct Node *node)
{
    // base case
    if (node == NULL)
    {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);
    int ans = max(left, right) + 1;
    return ans;
}
bool isBalanced(Node *root)
{
    // base case
    if (root == NULL)
    {
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    //difference between left and right sub tree node height cannot be more than 1 for a balanced tree
    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool,int> isBalancedFast(Node* root){

    
    //base case
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<int,int> left=isBalancedFast(root->left);
    pair<int,int> right=isBalancedFast(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;

    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    
    if(leftAns&&rightAns&&diff){
        ans.first=true;
    }
    else ans.first=false;

    return ans;
}
int main()
{
    Node *root=NULL;
    root=buildTree(root);
    //balance data-> 1 2 4 -1 7 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 9 10 -1 -1 -1
    //not balance data-> 1 2 4 -1 7 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 9 10 11 -1 -1 -1 -1 
    levelOrderTraversal(root);
    pair<bool,int> check=isBalancedFast(root);
    if(check.first==true)cout<<"tree is balanced"<<endl;
    else cout<<"tree is not balanced";
    return 0;
}