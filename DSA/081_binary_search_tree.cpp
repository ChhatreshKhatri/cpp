#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;

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
void inOrderTraversal(Node *root){
    //base case
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root==NULL)return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void insertInBst(Node *&root,int data){
    if(root==NULL){
        root=new Node(data);
        return;
        }
    if(data<root->data)insertInBst(root->left,data);
    if(data>root->data)insertInBst(root->right,data);
    
}
int main(){
    Node *root=NULL;

    cout<<"enter data to create BST "<<endl;
    takeInput(root);
    //10 8 21 7 27 5 4 3 -1
    cout<<"printing BST level order"<<endl;
    levelOrderTraversal(root);
    cout<<"\nprinting BST in order"<<endl;
    inOrderTraversal(root);
    cout<<"\nprinting BST pre order"<<endl;
    preOrderTraversal(root);
    cout<<"\nprinting BST post order"<<endl;
    postOrderTraversal(root);
    
    //insertion TC-> O(logn) same as binary search
    insertInBst(root,2);
    cout<<endl<<"printing BST level order after insertion of 2 "<<endl;
    levelOrderTraversal(root);

    insertInBst(root,20);
    cout<<endl<<"printing BST level order after insertion of 2 "<<endl;
    levelOrderTraversal(root);

    insertInBst(root,28);
    cout<<endl<<"printing BST level order after insertion of 2 "<<endl;
    levelOrderTraversal(root);
    
    return 0;
}