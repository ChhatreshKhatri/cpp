#include<bits/stdc++.h>
using namespace std;
/*
Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without swapping i.e. by placing the number in its position by pushing every element one step forward. 
In simple terms use a technique like insertion sort which means inserting element in its correct place. 
*/

void stableSelectionSort(int a[], int n)
{
    // Iterate through array elements
    for (int i = 0; i < n - 1; i++)
    {
 
        // Loop invariant : Elements till a[i - 1]
        // are already sorted.
 
        // Find minimum element from
        // arr[i] to arr[n - 1].
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
 
        // Move minimum element at current i.
        int key = a[min];
        while (min > i)
        {
            a[min] = a[min - 1];
            min--;
        }
        a[i] = key;
    }
}
 
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int a[] = { 4, 5, 3, 2, 4, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    stableSelectionSort(a, n);
    printArray(a, n);
    return 0;
}