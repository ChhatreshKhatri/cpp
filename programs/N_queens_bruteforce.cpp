#include<bits/stdc++.h>
using namespace std;
//TC-> 3n*n^2 issafe 3n   and n^2 solveFun
//3n can be optimized by hashing
bool isSafe(int row,int col, vector<string> board,int n){
    //check upper diagnol ↖
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='q')return false;
        row--;
        col--;
    }
    col =dupcol;
    row=duprow;
    // check left to the queen <-q
    while(col>=0){
        if(board[row][col]=='q')return false;
        col--;
    }
    row=duprow;
    col=dupcol;
    //check down diagnolly ↙
    while(row<n && col>=0){
        if(board[row][col]=='q') return false;
        row++;
        col--;
    }
    return true;
}
void solveFun(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    //base
    if(col==n){
        ans.push_back(board);
        return;
    }
    //placing queen in row 
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='q';
            //placing queen col wise
            solveFun(col+1,board,ans,n);
            board[row][col]='.';//remove q when backltrack
        }
    }
}

int main(){
    int n=4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solveFun(0,board,ans,n);
    for(auto i: ans){
        for(auto x: i){
            cout<<x<<endl;
        }
        cout<<endl<<endl;
    }

    return 0;
}