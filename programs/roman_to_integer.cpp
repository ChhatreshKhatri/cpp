#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
        unordered_map<char,int> mp{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int ans =0;
    for(int i=0;i<s.size();i++){
        //check there's a smaller then minus else plus
        if(mp[s[i]]<mp[s[i+1]])
            ans-=mp[s[i]];
        else
            ans+=mp[s[i]];

            cout<<"index : "<<i<<" char "<<s[i]<<" ans "<<ans<<endl;
    }
    return ans;
    }
int main(){
    string str="MCMXCIV";
    cout<<romanToInt(str);

    return 0;
}