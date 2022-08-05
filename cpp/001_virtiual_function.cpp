#include <iostream>
using namespace std;
class A{
     public:
          virtual void fun(){
               cout<<"base "<<endl;
          }
          void fun1(){
            cout<<"base"<<endl;
          }
};
class B: public A{
     public:
          void fun(){
               cout<<"derived "<<endl;
          }
          void fun1(){
            cout<<"derived"<<endl;
          }
};
int main(){
     A *a=new B;
     a->fun();
     a->fun1();
     B *b=new B;
     b->fun();
     b->fun1();


     return 0;
}