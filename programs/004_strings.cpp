#include<bits/stdc++.h>
using namespace std;
/*
a and aa, aa is lexographically bigger
ab and ac, ac is lexographically bigger
abc and bcd, bcd is lexographically bigger
*/
//in strtcmp(str1,str2);
//if str1 is lexographically bigger than it returns +ve value
//if str1 = str2 returns 0
//if str2 is lexographically bigger than return -ve value
int main(){
    char str1[3]={'g','f','g'},//greater than all
         str2[3]={'a','b','c'},//smaller than all
         str22[4]={'a','b','c'},//
         str3[3]={'b','c','d'},//greater than str2,4,5
         str4[4]={'a','b','c','d'},//smaller than str2
         str5[3]={'a','b','c'},
         str6[3]={'a'},
         str7[3]={'a','a'};
    cout<<strcmp(str1,str2)<<endl;//1
    
    cout<<strcmp(str2,str3)<<endl;//-1
    
    cout<<strcmp(str2,str4)<<endl;//1
    //here str2 is greater as its size is less it compare to only
    cout<<strcmp(str22,str4)<<endl;//-1
    
    cout<<strcmp(str4,str2)<<endl;//-1
    
    cout<<strcmp(str3,str4)<<endl;//1
    
    cout<<strcmp(str3,str4)<<endl;//1

    cout<<strcmp(str3,str5)<<endl;//1

    cout<<strcmp(str6,str7);//-1

    string st="abc",st2="bcd";
    if(st==st2)cout<<"equal"<<endl;
    else if(st<st2)cout<<"st2 greater"<<endl;
    else cout<<"st1 greater"<<endl;
    return 0;
}