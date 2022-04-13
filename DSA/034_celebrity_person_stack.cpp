#include<bits/stdc++.h>
using namespace std;
/*
0 1 2 are elements 
        0   1   2
    0   0   1   0
    1   0   0   0
    2   0   1   0

*/
bool knows(vector<vector<int> >& M, int a, int b,int n){
        if(M[a][b]==1)
        return true;
        else 
        return false;
    }
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step 1 push all element in stack
        for(int i=0;i<n;i++){
            s.push(i);
            
        }
        //step 2 get two elements and compare them
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        //step 3 single element in stack is "potential celebrity"
        //verificaton
        int candidate=s.top();
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0){
                zeroCount++;
            }
        }
        //all zero in it
        if(zeroCount != n)
            return -1;
        //column check
        int oneCount=0;
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1){
                oneCount++;
            }
        }
        if(oneCount != n-1)
            return -1;
        
    return candidate;
    
    }
int main()
{
    vector<vector<int>> M = {{0, 1, 0},
         {0, 0, 0}, 
         {0, 1, 0}};
    cout<<"celebrity element is "<<celebrity(M,3);

return 0;
}