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
        ll temp = 0;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            ans = ans ^ v[i];
        }
        ll ans2 = 0;
        for (auto i : v)
        {
            i = i ^ ans;
            ans2 = ans2 ^ i;
        }
        if (ans2 != 0)
        {
            cout << -1 << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}
/*

1 2 5
6 6 6
7 4 3

*/