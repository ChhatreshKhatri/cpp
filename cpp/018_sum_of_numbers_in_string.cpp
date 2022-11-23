#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "12ab2asd14"; // 12+2+14
    string s = "";
    int ans = 0;
    for (auto ch : str)    {
        if (ch >= '0' && ch <= '9')s += ch;
        else{
            if (s != "")
                ans += stoi(s);
            s = "";
        }
    }

    if (s != "")ans += stoi(s);
    cout << ans;

    return 0;
}