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
        ll sum = (n * (n + 1) * ((4 * n) - 1)) / 6;

        ll op = max(1, int(n - 1));
        cout << sum << " " << (2 * n) - 1 << endl;
        ;
        ll row = n - 1;
        ll col = n - 1;
        cout << 1 << " " << n << " ";
        for (ll i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        for (ll i = 0; i < n - 1; i++)
        {
            cout << 1 << " " << row;
            for (ll j = 1; j <= n; j++)
            {
                cout << " " << j;
            }
            cout << endl;
            cout << 2 << " " << row << " ";
            for (ll j = 1; j <= n; j++)
            {
                cout << j << " ";
            }
            row--;
            cout << endl;
        }
    }
    return 0;
}