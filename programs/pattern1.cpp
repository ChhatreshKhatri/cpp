#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0,j=0;
    for(i=0;i<5;i++){
    int n=i;
        for(j=0;j<=i;j++){
            cout<<n<<"\t";
            n=n+(5-j);
        }
        cout<<endl;
    }

    return 0;
}