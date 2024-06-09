#include "bits/stdc++.h"
#include "algorithm"
using namespace std;

#define ll long long int

int main()
{
    ll t;
    ll t1 = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        string s;
        cin >> n;
        cin >> s;
        ll count = 0;
        for (ll i = 0, j = s.length() - 1; i < (s.length() / 2); i++, j--)
        {
            if (s[i] != s[j])
            {
                count++;
            }
        }
        for (ll i = 0; i < count; i++)
        {
            cout << 0;
        }
        if (n % 2 == 1)
        {
            for (ll i = 0; i < (n + 1 - (2 * count)); i++)
            {
                cout << 1;
            }
        }
        else
        {
            ll n1 = n + 1 - (2 * count);
            for (ll i = 0; i < n1; i++)
            {
                if (i % 2 == 1)
                    cout << 0;
                else
                    cout << 1;
            }
        }

        for (ll i = 0; i < count; i++)
        {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}