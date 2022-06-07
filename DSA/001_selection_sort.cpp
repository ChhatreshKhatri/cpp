#include <bits/stdc++.h>
using namespace std;
 
//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 //stable selection sort
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
//Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
/*
Complexity Analysis of Selection Sort:
Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

One loop to select an element of Array one by one = O(N)
Another loop to compare that element with every other Array element = O(N)
Therefore overall complexity = O(N)*O(N) = O(N*N) = O(N2)

Auxiliary Space: O(1) as the only extra memory used is for temporary variable while swapping two values in Array. The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 

Sort an array of strings using Selection Sort
Is Selection Sort Algorithm stable?
Stability : The default implementation is not stable. However it can be made stable. Please see stable selection sort for details.

Is Selection Sort Algorithm in-place?
Yes, it does not require extra space.
*/