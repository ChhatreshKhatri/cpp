#include <iostream>
using namespace std;
class A{
     public:
          virtual void fun(){
               cout<<"base virtual func"<<endl;
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
     A *aa=new A;
     cout<<"base class object and base class address"<<endl;
     aa->fun();
     aa->fun1();
     cout<<"base class object and derived class address"<<endl;
     A *a=new B;
     a->fun();
     a->fun1();
     cout<<"derived class object and derived class address"<<endl;
     B *b=new B;
     b->fun();
     b->fun1();


     return 0;
}