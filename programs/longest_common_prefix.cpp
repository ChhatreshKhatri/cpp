#include <bits/stdc++.h>
using namespace std;
//tc -> O(m*n)
//sc ans-> O(m)size of string
string longestCP(vector<string> &arr, int n)
{
    string ans = "";
    // pick first string and compare its char with other sting
    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i];
        bool match = true;
        // next strings
        for (int j = 1; j < n; j++)
        {
            // not match
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

//trie


int main()
{
    vector<string> arr={"hello","hell","hel"};
    cout<<longestCP(arr,3);
    return 0;
}