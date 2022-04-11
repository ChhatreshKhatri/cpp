#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1

//return true if there;s redundant bracket
#include<stack>
bool findRedundantBrackets(string &s)
//tc-O(n) single loop sc-O(1)
{
    stack<char> st;
	for(int i=0;i<s.length();i++){
		char ch=s[i];
		if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*'){
			//for '(' and operators
			st.push(ch);
		}
		else{
			//for lowercase letter and ')'
			if(ch==')'){
				bool isRedundant=true;
				while(st.top()!='('){
					char top=st.top();
					if(top=='+'||top=='-'||top=='/'||top=='*'){
						//for '(' and operators
						isRedundant=false;
					}
					st.pop();
				}
				if(isRedundant==true){
					return true;
				}
				st.pop();
			}
		}
	}
	return false;
}
int main()
{
    

return 0;
}