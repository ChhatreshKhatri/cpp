#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/n-queens/submissions/
void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow,
           vector<int> &upperDiagnol, vector<int> &lowerDiagnol,
           int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagnol[row + col] == 0 && upperDiagnol[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagnol[row + col] = 1;
            upperDiagnol[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiagnol, lowerDiagnol, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagnol[row + col] = 0;
            upperDiagnol[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    vector<int> leftRow(n, 0);
    vector<int> upperDiagnol(2 * n - 1, 0);
    vector<int> lowerDiagnol(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagnol, lowerDiagnol, n);

    return ans;
}
int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    vector<int> leftRow(n, 0);
    vector<int> upperDiagnol(2 * n - 1, 0);
    vector<int> lowerDiagnol(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagnol, lowerDiagnol, n);
    for (auto i : ans)
    {
        for (auto x : i)
        {
            cout << x <<endl;
        }
        cout<<endl;
    }

    return 0;
}