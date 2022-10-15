#include<bits/stdc++.h>
using namespace std;
int *fun(){
    int a=10;
    int *ptr=&a;//a has only local scope so its address can only exist winthin the scope only, if accessd outside of scope may give garbage or runtime error
    return ptr;
}
int *fun2(){
    int *ptr=new int;//dynamically allocated memory remains in heap
    *ptr=10;
    return ptr;
}
int main(){
    //ptr = (cast-type*) malloc(byte-size)
    int *ptr=ptr = (int*)malloc(5 * sizeof(int));// block of 20byte
    int *ptr2=(int*)calloc(5, sizeof(int));// array of 5 blocks of size 4

    
    cout<<*fun()<<endl;// still it gives correct value but not good practice
    cout<<*fun2();//good practice



    return 0;
}