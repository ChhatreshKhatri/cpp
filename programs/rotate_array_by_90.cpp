#include<bits/stdc++.h>
using namespace std;
//tc n^2 
//sc n^2
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
  int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
  return rotated;
}

//tc n^2 + n^2
// sc 1
void rotate2(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //reverse row wise
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }

//tc n^2
//sc 1
void roro(vector<vector<int>>& matrix, int i, int k, int n){
        for (int j=0; j<k; j++){
            int t = matrix[i][i+j];
            matrix[i][i+j] = matrix[n-i-1-j][i];
            matrix[n-i-1-j][i] =  matrix[n-i-1][n-i-1-j];
            matrix[n-i-1][n-i-1-j] = matrix[i+j][n-i-1];
            matrix[i+j][n-i-1] = t;
        }
    }

    void rotate3(vector<vector<int>>& matrix) {
        int i = 0, n = matrix.size();
        int k = n-1;
        while (k>0){
            roro(matrix,i,k,n);
            i++;
            k-=2;
        }
        return;
    }
int main(){
    

    return 0;
}