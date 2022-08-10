// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    // TC-> O(3n) SC->O(3h)
    int countNode(Node *root)
    {
        // base
        if (root == NULL)
            return 0;
        int ans = 1 + countNode(root->left) + countNode(root->right);
        return ans;
    }
    bool isCBT(Node *root, int index, int count)
    {
        if (root == NULL)
            return true;
        if (index >= count)
            return false;
        else
        {
            bool left = isCBT(root->left, 2 * index + 1, count);
            bool right = isCBT(root->right, 2 * index + 2, count);
            return left && right;
        }
    }
    bool isMaxOrder(Node *root)
    {
        // leaf node
        if (root->left == NULL && root->right == NULL)
            return true;
        // only left child
        if (root->right == NULL)
            return root->data >= root->left->data;
        else
        {
            // both child exists
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            // if(left && right && (root->data > root->left->data && root->data > root->right->data)){
            //     return true;
            // }
            // else return false;
            return left && right && (root->data >= root->left->data && root->data >= root->right->data);
        }
    }
    bool isHeap(struct Node *tree)
    {
        int index = 0;
        int totalCount = countNode(tree);
        if (isCBT(tree, index, totalCount) && isMaxOrder(tree))
            return true;
        else
            return false;
    }

    // TC->O(n) SC->O(n)
    bool isHeap2(Node *root)
    {
        // Your code here
        queue<Node *> q;
        q.push(root);
        bool nullish = false;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                if (nullish || temp->left->data > temp->data)
                {
                    return false;
                }
                q.push(temp->left);
            }
            else
            {
                nullish = true;
            }
            if (temp->right)
            {
                if (nullish || temp->right->data > temp->data)
                {
                    return false;
                }
                q.push(temp->right);
            }
            else
            {
                nullish = true;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc = 1;
    // scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // 10 20 30 40 60 N N
        //  60 50 40 30 20 10 N
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "binary tree is heap" << endl;
        else
            cout << "binary tree is not heap" << endl;
        if (ob.isHeap2(root))
            cout << "binary tree is heap" << endl;
        else
            cout << "binary tree is not heap" << endl;
    }

    return 0;
}
// } Driver Code Ends