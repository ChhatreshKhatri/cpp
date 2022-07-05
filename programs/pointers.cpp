#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;
    int *p = &i;
    // int* p2=&p; //wrong sytax to point a pointer
    int **p2 = &p;   // double pointer
    int ***p3 = &p2; // third pointer
    cout << i << " " << *p << " " << **p2 << " " << ***p3 << endl;
    cout << &i << " " << p << " " << p2 << " " << p3 << endl;
    cout << *&i << " " << *p << " " << *p2 << " " << *p3 << endl;
    cout << *&i << " " << *p << " " << **p2 << " " << **p3 << endl; //**p wrong syntax *& is right **& is wrong
    cout << *&i << " " << *p << " " << **p2 << " " << ***p3 << endl;
    //*-> dereference &-> address of
    cout << "\n ++*p \n";

    int arr[] = {10, 20};
    int *pt1 = arr;
    ++*pt1;
    printf("arr[0] = %d, arr[1] = %d, *pt1 = %d", arr[0], arr[1], *pt1);

    cout << "\n *p++ \n";

    int arr2[] = {10, 20};
    int *pt2 = arr2;
    *pt2++;
    printf("arr2[0] = %d, arr2[1] = %d, *pt2 = %d", arr2[0], arr2[1], *pt2);

    cout << "\n *++p \n";

    int arr3[] = {10, 20};
    int *pt3 = arr3;
    *++pt3;
    printf("arr3[0] = %d, arr3[1] = %d, *pt3 = %d", arr3[0], arr3[1], *pt3);

    return 0;
}