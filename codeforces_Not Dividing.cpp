#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (ll i = 0; i < n - 1; i++)
        {
            if (i > 0 && v[i] == 1 && v[i + 1] == 1 && v[i - 1] != 2)
            {
                v[i] = 2;
                v[i + 1] = 3;
                continue;
            }
            if (i > 0 && v[i] == 1 && v[i + 1] == 1 && v[i - 1] == 2)
            {
                v[i] = 3;
                v[i + 1] = 2;
                continue;
            }
            if (v[i] == 1 && v[i + 1] == 1)
            {
                v[i] = 3;
                v[i + 1] = 2;
                continue;
            }
            if (i > 0 && v[i] == 1 && v[i - 1] != 2)
            {
                v[i]++;
                if (v[i + 1] % 2 == 0)
                    v[i + 1]++;
                continue;
            }
            if (i > 0 && v[i] == 1 && v[i - 1] == 2)
            {
                v[i] = 3;
                if (v[i + 1] % 3 == 0)
                {
                    v[i + 1]++;
                }
                continue;
            }
            if (v[i] == 1)
            {
                v[i]++;
                if (v[i + 1] % 2 == 0)
                {
                    v[i + 1]++;
                }
                continue;
            }
            if (v[i + 1] % v[i] == 0)
            {
                v[i + 1]++;
            }
        }
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}