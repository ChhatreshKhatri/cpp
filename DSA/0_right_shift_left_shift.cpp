#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<(6>>3)<<endl;
    /*right shift >>
    6 in binary 110
    3 shifts of zero left to right 
    1st shift 110->011
    2nd shift 011->001
    3rd shift 001->000
    000 in decimal is 0*/
    cout<<(6<<3)<<endl;
    /*left shift <<
    6 in binary 110
    3 shifts of zero to left 
    1st shift 110->1100
    2nd shift 1100->11000
    3rd shift 11000->110000
    110000 in decimal is 48*/
return 0;
}