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
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        // important to remove the node from queue when it is being processed 
        if (temp == NULL)
        {
            // either root is NULL or the previous level is completed
            cout << endl;
            if (!q.empty())
                q.push(NULL); // queue has some node left
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
Node *insertIntoBst(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // right part me insert
        root->right = insertIntoBst(root->right, data);
    }
    else
    {
        // left part me insert
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}
bool recursiveSearchInBST(Node *root, int x)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (root->data > x)
        return recursiveSearchInBST(root->left, x);
    else
        return recursiveSearchInBST(root->right, x);
}
bool iterativeSearchInBST(Node *root, int data)
{
    Node *temp=root;
    while(temp!=NULL){
        if(temp->data==data)return true;
        if(temp->data>data)temp=temp->left;
        else temp=temp->right;
    }
    return false;
}
int main()
{
    Node *root = NULL;

    cout << "enter data to create BST " << endl;
    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1

    // recursion
    //     tC-> O(h) for normal bst
    //     for skwed bst O(n)
    //     SC-> O(height)
    bool ans=recursiveSearchInBST(root,27);
    if(ans==true)cout<<"element present recursive"<<endl;
    else cout<<"element not present recursive"<<endl;

    // iterative will have SC-> O(1)
    ans=iterativeSearchInBST(root,27);
    if(ans==true)cout<<"element present"<<endl;
    else cout<<"element not present"<<endl;

    return 0;
}