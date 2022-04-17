#include<bits/stdc++.h>
using namespace std;
//   {{{}}   ->  {}{}
//minimum cost to make a string valid
//https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

/*
a=closed brackets
b=open brackets
if a=odd and b=even || a=even and b=odd then return -1; odd string
a=odd b=odd || a=even b=even the procede

{{{{ -> {}{} -> operations 2(2nd and 4th brackets changed)
a=4 b=0
(a+1)/2  +  (b+1)/2 =(4+1)/2=>2    +(0+1)/2=>0  =2+0 = 2 
}}}{{{ -> {}{}{}  ->operations 4(1st 3rd 4th and 6th brackets changed)
a=3 b=3
(a+1)/2  +  (b+1)/2 =(3+1)/2+(3+1)/2 =4  

*/

#include<stack>
int findMinimumCost(string str) {
  //odd str case
	if(str.length()%2==1){
		return -1;
	}
	stack<char> s;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
	
		if(ch=='{')
			s.push(ch);
		else{
			//ch is closed brace
			if(!s.empty()&&s.top()=='{'){
				s.pop();
			}
			else{
				s.push(ch);
			}
		}
	}	
	//stack contain invalid expression
	int a =0,b=0;
	while(!s.empty()){
		if(s.top()=='{'){
			b++;
		}
		else{
			a++;
		}
		s.pop();
	}
	
	int ans =(a+1)/2 +(b+1)/2;
	return ans;
}
int main()
{
    string s="{}{}}}";
	int ans=findMinimumCost(s);
	cout<<ans;
	//minimum change required to make all braces valid

return 0;
}