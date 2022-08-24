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
int main()
{

    return 0;
}