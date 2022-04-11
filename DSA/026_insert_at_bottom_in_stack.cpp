#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
void solve(stack<int>& s,int x){
    //tc-o(n) sc-O(n)
    //Stack space in recursive calls counts too as extra space required by a program
    //To generalize, a recursive function's memory complexity is O(recursion depth) . As our tree depth suggests, we will have n total return statements and thus the memory complexity is O(n)
	if(s.empty()){
		s.push(x);
		return ;
	}
	int num=s.top();
	s.pop();
	solve(s,x);
	s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
	return myStack;
}

int main()
{
    

return 0;
}