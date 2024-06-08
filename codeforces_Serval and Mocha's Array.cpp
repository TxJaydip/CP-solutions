#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<ll>
#define vvi vector<vector<ll>>
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
        ll gcd;

        for (ll i = 0; i < n; i++)
        {
            // cout << "GCD: " << gcd << endl;
            cin >> v[i];
        }

        for (ll i = 0; i < n - 1; i++)
        {
            bool flag = 0;
            for (ll j = i + 1; j < n; j++)
            {
                gcd = __gcd(v[i], v[j]);
                if (gcd <= 2)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (gcd <= 2)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}