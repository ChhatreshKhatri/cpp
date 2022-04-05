#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=5;
    int* p=&i;
    // int* p2=&p; //wrong sytax to point a pointer
    int **p2=&p; //double pointer
    int ***p3=&p2; //third pointer
    cout<<i<<" "<<*p<<" "<<**p2<<" "<<***p3<<endl;
    cout<<&i<<" "<<p<<" "<<p2<<" "<<p3<<endl;
    cout<<*&i<<" "<<*p<<" "<<*p2<<" "<<*p3<<endl;
    cout<<*&i<<" "<<*p<<" "<<**p2<<" "<<**p3<<endl;//**p wrong syntax *& is right **& is wrong 
    cout<<*&i<<" "<<*p<<" "<<**p2<<" "<<***p3<<endl;
    //*-> dereference &-> address of 

return 0;
}