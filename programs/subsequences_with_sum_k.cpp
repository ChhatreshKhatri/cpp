#include <bits/stdc++.h>
using namespace std;
void printS(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    // pick
    ds.push_back(arr[index]);
    s += arr[index];
    printS(index + 1, ds, s, sum, arr, n);

    // not pick
    s -= arr[index];
    ds.pop_back();
    printS(index + 1, ds, s, sum, arr, n);
}
// only once
bool printSOnce(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        // condition
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;//it will not execute further if satisfied
        }
        //condition not satisfied
        else    return false;
    }
    // pick
    ds.push_back(arr[index]);
    s += arr[index];
    if(printSOnce(index + 1, ds, s, sum, arr, n)==true)return true;

    // not pick
    s -= arr[index];
    ds.pop_back();
    if(printSOnce(index + 1, ds, s, sum, arr, n)==true)return true;

    return false;
}
int printSModified(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    // if(s>sum)return 0;//strictly for positives
    if (index == n)
    {
        // condition
        if (s == sum)
        {
            return 1;//it will not execute further if satisfied
        }
        //condition not satisfied
        else    return 0;
    }
    // pick
    ds.push_back(arr[index]);
    s += arr[index];
    int l=printSModified(index + 1, ds, s, sum, arr, n);

    // not pick
    s -= arr[index];
    ds.pop_back();
    int r=printSModified(index + 1, ds, s, sum, arr, n);

    return l+r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);//TC-> O(n2^n) 

    cout<<"subsequence "<<printSModified(0,ds,0,sum,arr,n);//

    cout<<endl<<"return with first ans/subsequence"<<endl;    
    if(printSOnce(0,ds,0,sum,arr,n))cout<<"sequence present "<<endl;
    else cout<<"subsequence not present"<<endl;


    return 0;
}