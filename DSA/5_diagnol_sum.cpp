#include<bits/stdc++.h>
using namespace std;
int diagonals(vector<vector<int>> &num)
{
    int Sum=0;
//     int len=num.size();
    for(int i=0;i<num.size();i++){
        for(int j=0;j<num[i].size();j++){
            if(i==j){
                Sum+=num[i][j];
            }
            else if(i==num.size()-1-j){
                Sum+=num[i][j];
            }
        }
    }
    return Sum;
    
}
int main()
{
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout<<diagonals(vect);
return 0;
}