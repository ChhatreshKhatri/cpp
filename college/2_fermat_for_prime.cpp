#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
/*
a^n-1 mod n = 1 is prime else not prime
*/
void func(long long n){
    int a=rand()%(n-1);
    long long power=pow(a,n-1);
    // cout<<a<<endl;
    if(power%n==1){cout<<"prime"<<endl;}
    else{
        cout<<"is not prime"<<endl;
    }
}
int main()
{
    long long n;
    cout<<"enter a number ";
    cin>>n;
        auto start = high_resolution_clock::now();
        func(n);
        auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count();

return 0;
}