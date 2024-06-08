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
        ll n, m, k;
        cin >> n >> m >> k;
        vi v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vi v2 = v;
        vi rank;
        sort(v2.begin(), v2.end());
        for (ll i = 0; i < n; i++)
        {
        }
    }
    return 0;
}