#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare> minHeap;
    //step 1 insert first element of k arrays in heap TC-> O(klogk) SC->O(k)
    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    //step 2 insert heap top in ans and push same array element if present in heap TC-> O(nklogk) TC->O(nk) vector
    while(minHeap.size()>0){
        node* temp=minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        
        int i=temp->row;
        int j=temp->col;
        
        if(j+1<kArrays[i].size()){
            node* next=new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> v={{1,2,3,4,5},{6,7,8,9,10}};
    //TC-> klogk + nklogk 
    //SC-> O(k) + O(nk)
    vector<int> ans=mergeKSortedArrays(v,2);
    for(auto i:ans)cout<<i<<" ";

    return 0;
}