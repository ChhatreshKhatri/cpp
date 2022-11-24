#include<bits/stdc++.h>
using namespace std;

int main(){
    string src="aaaabbbc",ans="";
    int count=1,i;
    for(i=0;i<src.length()-1;i++){
      if(src[i]==src[i+1])count++;
      else{
          ans+=src[i]+to_string(count);
          count=1;
      }
  }
    ans+=src[i]+to_string(count);
    cout<<ans;

    return 0;
}