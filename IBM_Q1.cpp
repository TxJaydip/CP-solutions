#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0')
        {
            ans += 2;
            s[i] = '0';
        }
        else if (s[i] == '1' && s[i + 1] == '1')
        {
            ans += 1;
            s[i] = '0';
            s[i + 1] = '0';
        }
    }

    if (s[s.length() - 1] == '1')
    {
        ans += 2;
    }

    cout << ans << endl;
}