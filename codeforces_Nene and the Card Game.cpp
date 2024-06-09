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
        unordered_map<int, int> m;
        ll temp;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
        }
        for (auto i : m)
        {
            if (i.second == 2)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}