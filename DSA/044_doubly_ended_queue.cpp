#include<bits/stdc++.h>
using namespace std;
/* 
Double Ended queue
    ->input/enqueue/push both sides(front,rear)
    ->output/deueue/pop both sides(front,rear)
functions
    ->push_back
    ->push_front
    ->pop_front
    ->pop_back
*/

//import<queue>

int main()
{
    deque<int> d;
    d.push_front(12);
    d.push_back(14);
    cout<<"front "<<d.front()<<endl;
    cout<<"back "<<d.back()<<endl;
    cout<<"pop front "<<endl;
    d.pop_front();
    cout<<"pop back "<<endl;
    d.pop_back();
    if(d.empty())cout<<"empty";
    else cout<<"not empty";


return 0;
}