#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/average-of-levels-in-binary-tree/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// BFS
// TC-> O(n) number of nodes
// SC-> O(m) max number of nodes present in a level
vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    // while queue is not empty,temp node,pop from queue, update sum, push childs in queue
    while (!q.empty())
    {
        double sum = 0;
        double n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(sum / n);
    }
    return ans;
}

// DFS
//  TC - O(total no. of nodes in input tree) + O(total no. of levels)
//  SC - O(2*total no. of levels) + auxiliary space(recursion stack)
// vector<pair<int,int>> -> 2(int)*levels and recursion stack
vector<pair<long, int>> counter; //  stores ( sum at a level , no of elements in that level)
void dfs(TreeNode *root, int depth)
{
    if (!root)
        return;
    int a = root->val;
    // to check if we have any entry corresponding to current depth
    if (counter.size() <= depth)
    {                              
        counter.push_back({a, 1}); //  if  we are at depth 1 and only depth 0 is completed then counter.size()=1
    }
    else
    {
        counter[depth].first += a;
        counter[depth].second++;
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

vector<double> averageOfLevels2(TreeNode *root)
{
    counter.clear();
    dfs(root, 0);
    vector<double> ans;
    for (int i = 0; i < counter.size(); i++)
    {
        ans.push_back((double)counter[i].first / counter[i].second); // pushing in averages
    }
    return ans;
}

//2nd dfs
//map<level, pair<(sum at that level),(nodes at that level)>>
void dfs2(TreeNode* root, int level, map<int, pair<double, double>> &mp)
    {
        if(root == NULL) return;
        
        mp[level].first += root->val;
        mp[level].second++;
        
        dfs2(root->left, level+1, mp);
        dfs2(root->right, level+1, mp);
        
    }
    vector<double> averageOfLevels3(TreeNode* root) {
        vector<double> ans;
        map<int, pair<double, double>> mp;
        
        dfs2(root, 0, mp);
        
        for(auto &x:mp)
        {
            ans.push_back( x.second.first/x.second.second);
        }
        return ans;
    }
int main()
{

    return 0;
}