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

        ll temp;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
        }

        // cout << 8 << endl;
        // for (ll i = 0; i < 8; i++)
        // {
        //     cout << 1 << " " << n << endl;
        // }

        if (n % 2)
        {
            cout << 4 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << n - 1 << endl;

            cout << 2 << " " << n << endl;
            cout << 2 << " " << n << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << 1 << " " << n << endl;
            cout << 1 << " " << n << endl;
        }
    }
    return 0;
}