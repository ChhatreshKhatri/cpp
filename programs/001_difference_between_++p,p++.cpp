// https://www.geeksforgeeks.org/difference-between-p-p-and-p/?ref=lbp
#include <bits/stdc++.h>
using namespace std;
void func1()
{
    cout<<"arr= ";
    int arr[] = {10, 20};
    for(auto i:arr)cout<<i<<" ";cout<<endl;
    int *p = arr;
    ++*p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",arr[0], arr[1], *p);cout<<endl;
    return;
}
void func2()
{
    int arr[] = {10, 20};
    int *p = arr;
    *p++;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",arr[0], arr[1], *p);cout<<endl;
    return;
}
void func3()
{
    int arr[] = {10, 20};
    
    int *p = arr;
    *++p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",arr[0], arr[1], *p);cout<<endl;
    return;
}
int main()
{
    
    func1();func2();func3();
    return 0;
}