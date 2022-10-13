#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<<*(&arr+1)-arr<<endl;

    return 0;
}