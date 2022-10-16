#include<bits/stdc++.h>
using namespace std;
void f1()throw(){
    cout<<"f1 begins\n";
    throw 100;
    cout<<"f1 ends\n";//doesnt executes bz of exception
}
void f2()throw(){
    cout<<"f2 begins\n";
    f1();
    cout<<"f2 ends\n";//doesnt executes bz of exception
}
void f3()throw(){
    cout<<"f3 begins\n";
    try{
        f2();
    }
    catch(int i){
        cout<<"caught exception\n";
    }
    cout<<"f3 ends\n";//executes after exception
}
int main(){
    f3();
    cout<<"execution complete...."<<endl;

    return 0;
}