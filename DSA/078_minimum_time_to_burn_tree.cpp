// https://practice.geeksforgeeks.org/problems/burning-tree/1#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
// User function Template for C++

class Solution
{
public:
    // create mapping and return target Node
    Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {
        Node *res = NULL;
        queue<Node *> q;
        q.push(root);
        nodeToParent[root] = NULL; // root ka parent NULL
        // level order traversal to set node to parent mapping
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front->data == target)
            {
                res = front;
            }
            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res; // target node
    }
    // burn tree
    int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
    {
        map<Node *, bool> visited;
        queue<Node *> q;
        q.push(root);
        visited[root] = true;

        int ans = 0; // return ans time or steps required to burn tree
        while (!q.empty())
        {
            bool flag = 0; // to check addition in queue
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                // process neighbouring node
                Node *front = q.front();
                q.pop();
                // visit left child
                if (front->left && !visited[front->left])
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                // visit right child
                if (front->right && !visited[front->right])
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                // visit parent
                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if (flag == 1)
                ans++;
        }
        return ans;
    }
    int minTime(Node *root, int target)
    {
        /*
        step 1 : create nodeToParent  mapping
        step 2 : find target node
        step 3 : burn tree in min time
        */

        map<Node *, Node *> nodeToParent; // TC-> O(nlogn) inserstion  SC-> O(n)
        Node *targetNode = createParentMapping(root, target, nodeToParent);
        // level order traversal TC-> O(n) //SC->O(n)
        int ans = burnTree(targetNode, nodeToParent);
        // steps or time required to burn tree
        // burn TC-> O(n)

        // overall TC is O(nlogn)map and SC-> O(n)map
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    //1 2 3 4 5 N 6 N N 7 8 N 9 10 11 N N N 12 N N N 13
    //8
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}
// } Driver Code Ends