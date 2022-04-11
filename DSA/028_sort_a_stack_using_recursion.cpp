#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

/*
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.
*/

void sortedInsert(stack<int> &stack,int num){
	//base case
	if(stack.empty()||(!stack.empty()&&stack.top()<num)){
		stack.push(num);
		return ;
	}
	int n=stack.top();
	stack.pop();
	//recur call
	sortedInsert(stack,num);
	
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return ;
	}
	int num=stack.top();
	stack.pop();
	//recur call
	sortStack(stack);
	//sort func
	sortedInsert(stack,num);
}
int main()
{
    

return 0;
}