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
        if (n == k)
        {
            vector<int> v(n, 1);
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if (k == 1)
        {
            vector<int> v;
            for (ll i = 1; i <= n; i++)
            {
                v.pb(i);
            }
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}