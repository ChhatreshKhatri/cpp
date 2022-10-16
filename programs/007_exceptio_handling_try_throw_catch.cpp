#include<bits/stdc++.h>
using namespace std;
int average(int arr[],int n)throw(){
    if(n==0)throw string("array size is 0\n");
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum/n;
}
int main(){
    double x,y;
    // cin>>x>>y;
    try{
        if(x==0.0)throw 0;
        if(y==0.0)throw string("y is zero\n");
        if(x+y<0.0)throw (x+y);
    }
    catch(int e1){cout<<e1;}
    catch(string &se){cout<<se;}
    catch(...){cout<<"x+y is less than 0\n";}// ... means catch for all 
    //i/p 1-    x=0.0 y=0.0 
    //o/p 1-    0
    //i/p 2-    x=1.0 y=0.0
    //o/p 2-    y is zero
    //i/p 3-    x=-1.0 y=-2.0
    //o/p 3-    x+y is less than 0

    int arr[]={5,5,2},n=0;
    try{
        int res=average(arr,n);
        cout<<res;
    }
    catch(string &se){cout<<se;}
    cout<<"bye";
    return 0;
}