#include <iostream>
using namespace std;
class twostack
{
public:
    int size;
    int top1, top2;
    int *arr;
    twostack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    // pushing an element in first stack
    void push1(int element)
    {
        if (top2 - top1 > 1)
        { // that means it has empty space
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "stackoverflow" << endl;
        }
    }
    // pushing an element in second stack
    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--; // as right to left in stack 2
            arr[top2] = element;
        }
        else
        {
            cout << "stackoverflow" << endl;
        }
    }
    void pop1()
    {
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "stackunderflow" << endl;
        }
    }
    void pop2()
    {
        if (top2 < size)
        {
            top2++;
        } // as right to left ja rhe h
        else
        {
            cout << "stackunderflow" << endl;
        }
    }
    void printarr(){
     for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
        
    }
    void peek()
    {
        if (top1 >= 0 && size >= top2)
        {
            cout<<"This is top1:" <<top1<<"the element at "<<arr[top1]<<endl;
            cout<<"This is top2:" <<top2<<" "<<arr[top2]<<endl;
            // return 1;
        }
    }
};
int main()
{
    twostack s(6);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push2(4);
    s.push2(5);
    // cout << s.peek() << endl;
    // cout<<s.peek()<<endl;
    // cout<<arr[0]<<" "<<arr[1]<<endl;
    s.printarr();
    cout<<endl;
    s.peek();
    
    return 0;
}