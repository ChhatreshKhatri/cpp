#include<bits/stdc++.h>
using namespace std;
/*
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/
 vector<int> nextSmallerElement(int* arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(int* arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(int* heights, int n)
{
    // int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = INT_MIN;
    //for other rows
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            // if heights=2,2,2,2,2 then n=-1 -1 -1 -1 -1 and p=-1 -1 -1 -1 -1 so,
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int maxArea(int M[4][4], int n, int m) {
        //step 1 1st row area
        int area=largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //update row: by adding previous row's value
                if(M[i][j]!=0)
                    M[i][j]=M[i][j]+M[i-1][j];
                else
                    M[i][j]=0;
            }
            // entire row is updated
            area=max(area,largestRectangleArea(M[i],m));
        }
        return area;
        
    }
int main()
{
    //TC-O(n*m) row*col
    //SC-O(m)->stack used for a row and its element, row has column size elements. 
    int M[4][4] = {{0, 1, 1, 0},
         {1, 1, 1, 1},
         {1, 1, 1, 1},
         {1, 1, 0, 0}};
    cout<<maxArea(M,4,4);

return 0;
}