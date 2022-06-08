#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    /*
    if(n%400==0)
        cout<<"Vicky can celebrate his birthday.";
    else if(n%100==0)cout<<"Vicky can't celebrate.";
    else if(n%4==0)cout<<"Vicky can celebrate his birthday.";    
    else cout<<"Vicky can't celebrate.";
    */
      if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
   cout<<n<<" is a leap year";
   else
   cout<<n<<" is not a leap year";

    return 0;
}