#include <bits/stdc++.h>
using namespace std;
//boundary traversal anti clockwise
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

//anti clockwise
void traverseLeftAntiCLock(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    ans.push_back(root->data);
    if (root->left)
        traverseLeftAntiCLock(root->left, ans);
    else
        traverseLeftAntiCLock(root->right, ans);
}
void traverseLeafAnticlock(node *root, vector<int> &ans)
{
    // base
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeafAnticlock(root->left, ans);
    traverseLeafAnticlock(root->right, ans);
}
void traverseRightAnticlock(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    if (root->right)
        traverseRightAnticlock(root->right, ans);
    else
        traverseRightAnticlock(root->left, ans);
    // after these calls
    ans.push_back(root->data);
}
vector<int> boundaryAntiCLockwise(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);

    // left part print or store
    traverseLeftAntiCLock(root->left, ans);

    // traverse leaf nodes
    // left subtree
    traverseLeafAnticlock(root->left, ans);
    // right subtree
    traverseLeafAnticlock(root->right, ans);

    // traverse right
    traverseRightAnticlock(root->right, ans);

    return ans;
}

//clock wise

void traverseLeftCLockwise(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    if (root->left)
        traverseLeftCLockwise(root->left, ans);
    else
        traverseLeftCLockwise(root->right, ans);
    ans.push_back(root->data);
}
void traverseLeafClockwise(node *root, vector<int> &ans)
{
    // base
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeafClockwise(root->right, ans);
    traverseLeafClockwise(root->left, ans);
}
void traverseRightClockwise(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->right)
        traverseRightClockwise(root->right, ans);
    else
        traverseRightClockwise(root->left, ans);
    // after these calls
}
vector<int> boundaryClockWise(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);

    // traverse right
    traverseRightClockwise(root->right, ans);

    // traverse leaf nodes
    // right subtree
    traverseLeafClockwise(root->right, ans);
    // left subtree
    traverseLeafClockwise(root->left, ans);

    // left part print or store
    traverseLeftCLockwise(root->left, ans);

    return ans;
}
int main()
{
    node *root = NULL;
    // tree
    root = buildTree(root);
    //data-> 1 2 4 -1 7 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 9 10 -1 -1 -1 
    //6 will be hidden between 1 and 6
    // data->  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    /*
                  1
            3          5       
          7   11     17  N
         N N N  N   N  N 
    */
    // level order traversal
    cout << "level order traversal " << endl;
    levelOrderTraversal(root);
    cout<<endl<<"boundary traverse"<<endl;
    vector<int> ans=boundaryAntiCLockwise(root);
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
    vector<int> ans2=boundaryClockWise(root);
    for(auto i: ans2)cout<<i<<" ";


    return 0;
}