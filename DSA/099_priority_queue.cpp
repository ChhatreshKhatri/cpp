#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"using priority queue"<<endl<<endl;
    cout<<"max heap"<<endl;
    //max heap -> top is max element
    priority_queue<int> pq; 
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);
    cout<<"top element "<<pq.top()<<endl;
    pq.pop();
    cout<<"after top element popped, new top "<<pq.top()<<endl;
    cout<<"pq size "<<pq.size()<<endl;
    if(pq.empty()) cout<<"pq is empty"<<endl;
    else cout<<"pq is not empty"<<endl<<endl;

    cout<<"min heap"<<endl;
    //min heap -> top is min element
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(1);
    cout<<"top element "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"after top element popped, new top "<<minheap.top()<<endl;
    cout<<"minheap size "<<minheap.size()<<endl;
    if(minheap.empty()) cout<<"minheap is empty"<<endl;
    else cout<<"minheap is not empty"<<endl;

    return 0;
}