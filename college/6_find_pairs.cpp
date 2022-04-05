#include<bits/stdc++.h>
using namespace std;
void findpairs(vector<int> v,int n){
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if((v[i]+v[j])%60==0){
                cout<<v[i]<<" "<<v[j]<<endl;
            }
        }
    }
}
int main()
{
    vector<int> v={10,20,30,40,50,60,80,100,120,150};
    findpairs(v,60);

return 0;
}