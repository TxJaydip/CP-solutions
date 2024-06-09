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
    ll t, n, m, k, temp;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n >> m >> k;
        vector<ll> b;
        vector<ll> c;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            b.pb(temp);
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> temp;
            c.pb(temp);
        }
        ll ans = 0;
        for (auto i : b)
        {
            for (auto j : c)
            {
                if (i + j <= k)
                    ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
