#include<bits/stdc++.h>
using namespace std;
class summer{
    public:
    summer(){
        cout<<"this is constructor in summer"<<endl;
    }
    void print(){
        cout<<"print func in summer"<<endl;
    }
};
struct account{
    string name;
    int num;
    void print(){
        cout<<"name from account "<<name<<endl;
    }
};
int main()
{
    summer *s,a;
    s=&a;
    (*s).print();
    s->print();
    account p,*ptr;
    ptr=&p;
    (*ptr).name="hello";
    (*ptr).print();
    ptr->name="h!!";
    ptr->print();

return 0;
}