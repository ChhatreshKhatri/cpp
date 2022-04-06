#include<bits/stdc++.h>
using namespace std;
//stack implementation
class istack{
    public:
    int *arr;
    int top;
    int size;
    //constructor
    istack(int size){
        this->size=size;
        arr=new int(size);
        top=-1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;            
        }
        else{cout<<"stack overflow"<<endl;}
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{cout<<"stack underflow, stack empty"<<endl;}
    }
    int peek(){
        if(top>=0)
            return arr[top];
        else{cout<<"stack is empty"<<endl;return -1;}
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{return false;}
    }
};
int main()
{
    //stl
    stack<int> s;
    //push
    s.push(2);    s.push(1);    s.push(3);    s.push(4);
    //pop
    s.pop();//3
    //peek
    cout<<s.top()<<endl;
    //if empty
    if(s.empty()){cout<<"stack is empty"<<endl;}
    else{cout<<"stack not empty"<<endl;}
    //size
    cout<<s.size()<<endl;//3

    //self made
    istack st(5);//5 is size
    st.push(40);
    st.push(13);
    cout<<st.peek()<<endl;
    st.isEmpty()?cout<<"stack is empty"<<endl : cout<<"is not empty"<<endl; 
    
    st.pop();
    st.pop();
    st.pop();
    st.isEmpty()?(cout<<"stack is empty"<<endl) : cout<<"is not empty";
    st.push(40);st.push(13);st.push(40);st.push(13);st.push(40);
    st.push(13); 
return 0;
}