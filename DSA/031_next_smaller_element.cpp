#include<bits/stdc++.h>
using namespace std;

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
	//tc-O(n)  sc-O(n)
    stack<int> s;
	s.push(-1);
	vector<int> ans(n);
	for(int i=n-1;i>=0;i--){
		int curr=arr[i];
		while(s.top()>=curr){
			s.pop();
		}
		//ans is stack top element
		ans[i]=s.top();
		s.push(curr);
	}
	return ans;
}
int main()
{
    vector<int> arr={2,1,4,3};
	vector<int> ans=nextSmallerElement(arr,4);
	// for(auto x:ans){
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
	// }

return 0;
}