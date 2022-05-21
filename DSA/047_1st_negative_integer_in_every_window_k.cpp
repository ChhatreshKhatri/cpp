#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(int A[], int N, int K)
{
    deque<long long int> dq;
    vector<long long> ans;
    // first kth window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // store ans of 1st kth window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    // process for remaining windows
    for (int i = K; i < N; i++)
    {
        //remove the front element which is already stored in ans of previous window
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        // addition of next window element
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        // store ans
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    int v[5] = {-8, 2, 3, -6, 10};
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<long long> vec = printFirstNegativeInteger(v, 5, 3);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}