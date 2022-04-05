#include<bits/stdc++.h>
using namespace std;
int main() {
    int nn;
    long long int numbr; 
    cin>>numbr;
    char arr[numbr];
    long long int countoverclocked=0;
    for(long long int indx=0;indx<numbr;indx++) 
    {
        cin>>arr[indx];
        if(arr[indx]=='O') countoverclocked++;
    }
    if(countoverclocked==0 || countoverclocked==numbr) 
    {
        cout<<0<<" "<<0;
        return 0;
    }
    long long int currentcounter=0;
    for(long long int j=0;j<countoverclocked;j++) 
    {
        if(arr[j]=='O') currentcounter++;
    }
    long long int finecounter=currentcounter;
    long long int mfactor=1;
    for(long long int i=countoverclocked;i<numbr;i++) 
    {
        if(arr[i]=='O') currentcounter++;
        if(arr[i-countoverclocked]=='O') currentcounter--;
        if(currentcounter > finecounter) 
        {
            mfactor=0;
            finecounter=currentcounter;
        }
        if(currentcounter==finecounter) mfactor++;
    }
    long long int answer=countoverclocked-finecounter;
    cout<<answer<<" "<<mfactor;
    return 0;
}