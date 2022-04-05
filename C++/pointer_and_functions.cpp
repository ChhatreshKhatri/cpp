#include<bits/stdc++.h>
using namespace std;
//size of pointer is 8 cz it takes two blocks for address and null char
int sum(int* a){
    int c=0;
    for(int i=0;i<4;i++)
    c=c+a[i];
    return c;
}
void sum2(int* a){//int a[] is same as int* a  
    int c=0;
    a[2]=100;
    for(int i=0;i<4;i++)
    c=c+a[i];
    cout<<c<<endl;
}
void update(int *a){
    a=a+10;
    cout<<*a<<endl;
}
void update2(int *a){
    *a=*a+10;
    cout<<*a<<endl;
}
void update3(int **a){
    **a=**a+10;
    cout<<**a<<endl;
}
int main()
{
    int a[]={1,2,3,4};
    int c=0;
    int* p=a;
    cout<<sum(p)<<endl;
    sum2(a);//in case of chars and arrays its call by reference, 
    for(int i=0;i<4;i++)
    c=c+a[i];
    cout<<c<<endl;
    //value at address is changed


    int n1=5; 
    int* n2=&n1;
    update(n2);//value at address is not changed
    cout<<*n2<<endl;
    update2(n2);//value changed becs value at address is changed
    cout<<*n2<<" "<<n1<<endl;
    
    
    int x=50;
    int *y=&x;
    int **z=&y;
    cout<<x<<endl;
    cout<<**z<<endl;
    update3(z);
    cout<<**z<<" "<<x<<endl;
    
return 0;
}