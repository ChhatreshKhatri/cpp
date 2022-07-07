#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertIntoBst(Node* root,int data){
    // base case
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        //right part me insert
        root->right=insertIntoBst(root->right,data);        
    }
    else{
        //left part me insert
        root->left=insertIntoBst(root->left,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL){
            // purana complete hogya toh next pe chalo
            cout << endl;
            if (!q.empty()){
                // queue still has child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}
Node *minValue(Node *root){
    if(root->left==NULL){return root;}
    else minValue(root->left);
    return root;
}
Node *deleteFromBST(Node *root,int val){
    //base case
    if(root==NULL)return root;
    if(root->data==val){
        //0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL&&root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL&&root->right!=NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL&&root->right!=NULL){
            int mini=minValue(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
        }
    }
    else if(root->data>val){
        //left part
        root->left=deleteFromBST(root->left,val);
        // return root;
    }
    else{
        //right
        root->right=deleteFromBST(root->right,val);
        //return root;
    }
    return root;
}
int main(){
    Node *root=NULL;
    cout<<"enter input"<<endl;
    takeInput(root);
    //data 10 8 21 7 27 5 4 3 -1
    //data 50 20 70 10 30 90 110 -1
    //               50
    //           20      70
    //         10  30  N    90
    //                        110
    cout<<"before deletion"<<endl;
    levelOrderTraversal(root);
    cout<<"after deletion"<<endl;
    root=deleteFromBST(root,30);
    levelOrderTraversal(root);
    cout<<"after insertion"<<endl;
    root=insertIntoBst(root,30);
    levelOrderTraversal(root);
    cout<<"after deletion"<<endl;
    root=deleteFromBST(root,90);
    levelOrderTraversal(root);

    return 0;
}