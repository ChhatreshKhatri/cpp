#include <bits/stdc++.h>
using namespace std;
class A
{
private:
    int data_a;

public:
    A(int x)
    {
        data_a = x;
    }
    friend int fun(A);
};

int fun(A a)
{
    return a.data_a;
}
int main()
{
    A a(10);
    cout << fun(a) << endl;
    return 0;
}
