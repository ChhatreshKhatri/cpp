#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
//tc-O(n^2) sc-O(n)
void insertAtBottom(stack<int> &stack,int num){
	//base case
	if(stack.empty()){
		stack.push(num);
		return ;
	}
	int n=stack.top();
	stack.pop();
	insertAtBottom(stack,num);
	stack.push(n);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
		return ;
	}
	int num=stack.top();
	stack.pop();
	//recursive call
	reverseStack(stack);
	
	insertAtBottom(stack,num);
}
int main()
{
    

return 0;
}