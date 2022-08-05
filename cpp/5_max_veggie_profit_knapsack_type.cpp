#include<bits/stdc++.h>
using namespace std;
class veg{
    public:
    string name;
    int quantity;
    int price;
};
void profit(vector<veg> v){
    

}
int main()
{
    veg v1,v2,v3,v4;
    v1.name="tomato";
    v1.quantity=4;
    v1.price=10;
    v2.name="potato";
    v2.quantity=5;
    v2.price=15;
    v3.name="brinjal";
    v3.quantity=3;
    v3.price=20;
    v4.name="ladyfinger";
    v4.quantity=4;
    v4.price=25;
    vector<veg> v={v1,v2,v3,v4};
    profit(v);
    

return 0;
}