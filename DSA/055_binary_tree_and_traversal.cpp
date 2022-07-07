#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for inserting in left" << endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in left" << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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
void inOrderTraversal(node *root){
    //base case
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root==NULL)return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


int main()
{
    node *root = NULL;
    // tree
    root = buildTree(root);
    // data->  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order traversal
    cout << "level order traversal " << endl;
    levelOrderTraversal(root);
    cout<<"inorder traversal"<<endl;
    inOrderTraversal(root);
    cout<<endl<<"preorder traversal"<<endl;
    preOrderTraversal(root);
    cout<<endl<<"postorder traversal"<<endl;
    postOrderTraversal(root);

    return 0;
}