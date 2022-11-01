#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,start,ans,end;cin>>a>>b;
    start=max(a,b);
    end=a*b;
    for(int i=start;i<=end;i++){
        if(i%a==0 && i%b==0){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    

    return 0;
}