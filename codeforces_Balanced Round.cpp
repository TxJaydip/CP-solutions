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
        ll n, k;
        cin >> n >> k;
        vi v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll max = 1;
        ll cnt = 1;
        for (ll i = 0; i < n - 1; i++)
        {
            if (v[i + 1] - v[i] <= k)
            {
                cnt++;
            }
            else
            {
                if (cnt > max)
                    max = cnt;
                cnt = 1;
            }
        }
        if (cnt > max)
            max = cnt;
        cout << n - max << endl;
    }
    return 0;
}