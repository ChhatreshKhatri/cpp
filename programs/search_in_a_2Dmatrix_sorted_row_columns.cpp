#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0, j = m - 1;
    while ((i >= 0 && i < n) && (j >= 0 && j < m))
    {
        cout<<"inside while"<<endl;
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {  {1,1} 
                                    // {15, 25, 35, 45}, 
                                    // {27, 29, 37, 45}, 
                                    // {32, 33, 39, 50}, 
                                    // {32, 33, 39, 50}
                                    };
    cout<<matrix.size();
    cout<<matrix[0].size();
    cout << searchMatrix(matrix, 2);

    return 0;
}