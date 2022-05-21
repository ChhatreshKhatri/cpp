#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/
queue<int> modifyQueue(queue<int> q, int k) {
        //pop 1st k from q and put in stack
    stack<int> s;
    //sc-O(n)
    for(int i=0;i<k;i++){//tc-O(k)
        int val=q.front();
        q.pop();
        s.push(val);
    }
    //fetch from stack and push in q
    while(!s.empty()){//tc-O(k)
        int val=s.top();
        s.pop();
        q.push(val);
    }
    //fetch first n-k element and push in stack
    int t=q.size()-k;
    while(t--){//tc-O(n-k)
        int val=q.front();
        q.pop();
        q.push(val);
    }
    //tc-O(n)
    //sc-O(n)
    return q;

}
int main()
{
    

return 0;
}