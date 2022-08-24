#include <bits/stdc++.h>
using namespace std;
// TLE
bool isPowerOfFour(int n)
{
    if (n == 1)
        return 1;
    while (n != 1)
    {
        if (n % 4 != 0)
            return 0;
        n = n / 4;
    }
    return 1;
}
// Optimize
bool isPowerOfFour2(int n) {
        return n > 0 && (n & (n-1)) == 0 && (n-1)%3 == 0; 
    }
int main()
{

    return 0;
}