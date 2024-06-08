#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<ll>
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
        ll max1 = 0;
        ll min1 = INT_MAX;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i != 0)
                max1 = max(max1, v[i]);
            if (i != n - 1)
                min1 = min(min1, v[i]);
        }
        ll maxi = v[n - 1] - v[0];
        for (ll i = 0; i < n - 1; i++)
        {
            maxi = max(maxi, v[i] - v[i + 1]);
        }
        maxi = max(maxi, max1 - v[0]);
        maxi = max(maxi, v[n - 1] - min1);
        cout << maxi << endl;
    }
    return 0;
}