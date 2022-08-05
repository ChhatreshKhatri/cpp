#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void func(long long n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"not prime"<<endl;
            break;
        }
        else{cout<<"is prime"<<endl;
        break;}
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