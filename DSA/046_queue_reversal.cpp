#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int> rev(queue<int> q);

int main()
{
    queue<int> q;
    q.push(1);q.push(2);q.push(3);q.push(4)q.push(5);q.push(6);
    queue<int> a=rev(q);
    //TC-O(n)
    //SC-O(n)
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    while(!a.empty()){
        cout<<a.front()<<" ";
        a.pop();
    }
    

return 0;
}
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    return q;
}