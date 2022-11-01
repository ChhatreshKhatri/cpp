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
void func2(long long n){
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            cout<<"not prime";break;
        }
        else cout<<"not prime";break;
    }
}
int main()
{
    long long n;
    cout<<"enter a number"<<endl;
    cin>>n;
        auto start = high_resolution_clock::now();
        func(n);
        auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;
    func2(n);

return 0;
}