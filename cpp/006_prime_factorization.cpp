#include<bits/stdc++.h>
using namespace std;
int isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0)return false;
    }
    return true;
}
void prime_factors(int n){
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            int x=i;
            while(n%x==0){
                cout<<i<<" ";
                x=x*i;
            }
        }
    }
}
void primeFactors(int n)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
        cout<<c<<" ";
        n/=c;
        }
        else c++;
    }
}
int main(){
    int n;
    cin>>n;
    prime_factors(n);cout<<endl;
    primeFactors(n);

    return 0;
}