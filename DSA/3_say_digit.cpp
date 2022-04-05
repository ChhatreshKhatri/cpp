#include<bits/stdc++.h>
using namespace std;
void saydigit(int n,string arr[]){
    // cout<<n<<endl;
    if(n==0)return;
    int digit=n%10;
    n=n/10;
    cout<<arr[digit]<<" ";//two,one,four
    saydigit(n,arr);
}
void saydigit2(int n,string arr[]){
    // cout<<n<<endl;
    if(n==0)
        return ;
    int digit=n%10;
    n=n/10;
    saydigit2(n,arr);
    cout<<arr[digit]<<" ";//four,one,two
}

int main()
{
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n=412;
    // cin>>n;
    cout<<endl;
    saydigit(n,arr);

    cout<<endl;
    saydigit2(n,arr);


return 0;
}