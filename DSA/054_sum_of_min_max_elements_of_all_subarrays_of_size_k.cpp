#include<bits/stdc++.h>
using namespace std;
int solve(int* arr,int n,int k){
    deque<int>maxi(k);
    deque<int>mini(k);
    //addition of first k size windows
    for(int i=0;i<k;i++){
        while(!maxi.empty()&&arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        while (!mini.empty()&&arr[mini.back()]>=arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    
    int ans=0;
    ans+=arr[maxi.front()]+arr[mini.front()];
    //remaining windows ko process krlo
    for(int i=k;i<n;i++){
        // next window
        //removal
        while(!maxi.empty()&&i-mini.front()<=arr[i])
            maxi.pop_back();
        while(!mini.empty()&&i-mini.front()>=k)
            mini.pop_front();
        //addition
        while(!maxi.empty()&&arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        while(!mini.empty()&&arr[mini.back()]>=arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);

        ans+=arr[maxi.front()]+arr[mini.front()];
        //last window processed here
    }

    return ans;
}
int solve2(int* arr,int n,int k){
    deque<int>maxi(k);
    deque<int>mini(k);
    //addition of first k size windows
    for(int i=0;i<k;i++){
        while(!maxi.empty()&&arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        while (!mini.empty()&&arr[mini.back()]>=arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
    for(int i=k;i<n;i++){        
        ans+=arr[maxi.front()]+arr[mini.front()];
        // next window
        //removal
        while(!maxi.empty()&&i-maxi.front()<=arr[i])
            maxi.pop_back();
        while(!mini.empty()&&i-mini.front()>=k)
            mini.pop_front();
        //addition
        while(!maxi.empty()&&arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        while(!mini.empty()&&arr[mini.back()]>=arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
    }
    //for last window to process separately
    ans+=arr[maxi.front()]+arr[mini.front()];

    return ans;
}
int main(){
    int arr[7]={2,5,-1,7,-3,-1,-2};
    cout<<"ans= "<<solve2(arr,7,4)<<endl;
    cout<<"ans= "<<solve(arr,7,4)<<endl;

    int arr2[6]={5,-1,7,-3,-1,-2};
    cout<<"ans= "<<solve(arr2,6,4)<<endl;
    cout<<"ans= "<<solve2(arr2,6,4)<<endl;

    return 0;
}