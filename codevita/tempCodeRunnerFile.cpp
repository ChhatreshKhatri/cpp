#include <bits/stdc++.h>

using namespace std;

unordered_set < char >st;
//string ls = "lkahgfswetimncx96345@#) (";


void habibi (string ls, string s)
{
    for(int i=0;i<s.size();i++) s[i]=tolower(s[i]);
  string res = "";
  for (int i = 0; i < s.size (); i++)
    if ((s[i] == ' ') || (st.count (s[i])))
      {
	res.push_back (s[i]);
      }

  unordered_map < char, int >mp;
  for (int i = 0; i < res.size (); i++)
    mp[res[i]]++;

  string f = "";

  for (int i = 0; i < ls.size (); i++)
    if (mp.count (ls[i]))
      {
	for (int j = 0; j < mp[ls[i]]; j++)
	  f.push_back (ls[i]);
      }
  cout << f << " ";
}

int main ()
{
    int flag=0;
  string ls,s,x;  
  getline(cin,ls);
  getline(cin,s);
  for (int i = 0; i < ls.size (); i++)
    if (st.count (ls[i]))
      {
	cout << "New Language Error";
	return 0;
      }
    else
      st.insert (tolower (ls[i]));
  for(int i=0;i<s.size();i++)
  {
      if(s[i]==' ' && x.length()>0) 
      {
           habibi(ls,x);
           x = "";
           flag=1;
      }
      else 
      {
          x.push_back(s[i]);  
          flag=0;
      }

  }
  if(flag==0)   habibi(ls,x);

  return 0;
}