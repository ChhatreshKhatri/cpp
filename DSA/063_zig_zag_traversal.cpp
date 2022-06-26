#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root==NULL)return result;
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight=true;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> ans(size);
    	    //level process
    	    for(int i=0;i<size;i++){
    	        Node* frontNode=q.front();
    	        q.pop();
    	        //normal insert or reverse insert
    	        int index=leftToRight?i:size-i-1;
    	        ans[index]=frontNode->data;
    	        
    	        if(frontNode->left)q.push(frontNode->left);
    	        if(frontNode->right)q.push(frontNode->right);
    	    }
    	    //change directoin
    	    leftToRight=!leftToRight;
    	    for(auto i:ans){
    	        result.push_back(i);
    	    }
    	    
    	}
    	return result;
    }
Node *buildTree(Node *root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for inserting in left" << endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in right" << endl;
    root->right = buildTree(root->right);

    return root;
}

int main(){
    Node *n=NULL;
    n=buildTree(n);
    //1 2 -1 -1 3 4 -1 -1 5 -1 -1
    vector<int> ans=zigZagTraversal(n);
    cout<<"zig zag traversal"<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";

    return 0;
}