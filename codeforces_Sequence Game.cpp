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
        vi a;
        a.pb(v[0]);
        // a.pb(1);
        for (ll i = 1; i < n; i++)
        {
            if (v[i] >= v[i - 1])
            {
                a.pb(v[i]);
                continue;
            }
            a.pb(1);
            a.pb(v[i]);
        }
        cout << a.size() << endl;
        for (ll i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}