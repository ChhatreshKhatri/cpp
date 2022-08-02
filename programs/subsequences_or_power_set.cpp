#include<bits/stdc++.h>
using namespace std;
//2 to the power n subsequences
/*
arr-> 3,1,2
subsequences(contigous/inplace)
3
1
2
3,1
1,2
3,2        3 before 2 
3,1,2
power set(contigous/inplace)
{}
3
1
2
3,1
1,2
3,2        3 before 2 
3,1,2

arr->    213
arr->    abc 0->not taken 1->taken
    0    000->0
    1    001->a
    2    010->b
    3    011->ab
    4    100->c
    5    101->ac
    6    110->bc
    7    111->abc
*/
void subsequence(int index,vector<int> &ds,int arr[],int n){
    if(index==n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }
    ds.push_back(arr[index]);
    subsequence(index+1,ds,arr,n);
    ds.pop_back();
    subsequence(index+1,ds,arr,n);
}
int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    subsequence(0,ds,arr,n);
    //tc-> O(n2ⁿ) sc-> O(n)
    return 0;
}