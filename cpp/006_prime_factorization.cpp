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
void primefactorsOptimized(int n){
    while(n%2==0){
        cout<<2<<" ";
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>2)cout<<n<<" ";//for primes
}
int main(){
    int n;
    cin>>n;
    prime_factors(n);cout<<endl;//TC O(n^2)
    primeFactors(n);cout<<endl;//TC O(n)
    primefactorsOptimized(n);//TC O(log(n))

    return 0;
}