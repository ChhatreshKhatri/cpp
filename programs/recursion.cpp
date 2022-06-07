#include<bits/stdc++.h>
using namespace std;
void func1(int n){
    if(n==0)return;
    cout<<n<<endl;
    func1(n-1);

}
void func2(int n){
    if(n==0)return;
    func2(n-1);
    cout<<n<<endl;

}
int main()
{
    int n;
    cout<<"enter a num";
    cin>>n;
    func1(n);
    cout<<endl;
    func2(n);

return 0;
}