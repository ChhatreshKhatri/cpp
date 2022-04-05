#include <bits/stdc++.h>
using namespace std;

string sol(string s, string c)
{
    string s="palskdjfieuryt93516247oh",c="Philacodist 2021",ans,fans;
    //cin >>s>>c;
    map<char,int> seq,cc;
    vector <char> key;
    set <int> spaces;
    int ind = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')   continue;
        seq[s[i]]++;
        key.push_back(s[i]);
        if(seq[s[i]]>1)
        {
            cout << "New Language Error";
            return -1;
        }
    }
    for(int i=0;i<c.size();i++)
    {
        if(c[i] == ' ')
        {
            spaces.insert(i); 
            continue;
        }
        if(c[i] > 64 && c[i] < 91)  cc[c[i]+32]++;
        
        else cc[c[i]]++;
    }
    
    for(int i=0;i<key.size();i++)
    {
        if(cc[key[i]] > 0) 
        {
            for(int j=0;j<cc[key[i]];j++)
            {
                if(spaces.find(ind)!=spaces.end())    
                {
                    ans.push_back(' '); ind++;
                }
                ans.push_back(key[i]);
                ind++;
            }
        }
    }
    cout << ans;
    return 0; 
    
}

int main()
{
    string s="palskdjfieuryt93516247oh",c="Philacodist 2021",ans,fans;
    for(int i=0;i<c.size();i++)
    {
        if(c[i] == ' ')
        {

            fans.push_back(' ');
        }
    }
}