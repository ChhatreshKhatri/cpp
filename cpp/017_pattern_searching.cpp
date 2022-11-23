#include<bits/stdc++.h>
using namespace std;

int main(){
    string text="geeksforgeeksforgeeks";
    string pattern="geeks";
    int found=text.find(pattern);
    while(found!=string::npos){
        cout<<"pattern found at "<<found<<endl;
        found=text.find(pattern,found+1);
    }

    return 0;
}