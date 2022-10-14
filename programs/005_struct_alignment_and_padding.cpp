#include<bits/stdc++.h>
using namespace std;
struct st1{
    char ch;
    char ch2;
    double d;
};
//(1 + 1 + 6) + (8) = 16
// alignment depends on largest data member
// 6 is padding here
struct st2{
    char ch;
    double d;
    char ch2;
};
//(1 + 7) + (8) + (1+7) = 24
//alignment is according to largest data member size
//both 7 are padding here
struct st3{
    double d;
    char ch;
    char ch2;
};
// (8)+ (1+1+6) = 16

struct st4 {
    char ch;
    double d;
    char ch2;
}__attribute__((packed));
//1+8+1 = 10
//it will remove padding 
//due to alignment of 8 processor will take 2 cycles to read whole 
//in previous unpacked struct cpu will will read read whole in 1 cycle 
int main(){
    cout<<sizeof(st1)<<endl;
    cout<<sizeof(st2)<<endl;
    cout<<sizeof(st3)<<endl;
    cout<<sizeof(st4)<<endl;
    return 0;
}