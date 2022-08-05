#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> v, int n){
    if(n==0){
        cout<<"value is 0";
        return;
    }
    int count=0;
    for(int i=0;i<v.size();i++){
    count=count+n/v[i];
    n=n%v[i];
    }
    cout<<count;

}
int main()
{
     vector<int> v={10,5,2,1};
    int n=0;
    cout<<"enter your value ";
    cin>>n;
    solve(v,n);

return 0;
}