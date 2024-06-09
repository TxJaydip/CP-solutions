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
        char a[2 * n][2 * n];
        for (ll i = 0; i < 2 * n; i += 4)
        {
            for (ll j = 0; j < 2 * n; j += 4)
            {
                a[i][j] = '#';
                a[i + 1][j] = '#';
                a[i][j + 1] = '#';
                a[i + 1][j + 1] = '#';
            }
        }
        for (ll i = 0; i < 2 * n; i += 4)
        {
            for (ll j = 2; j < 2 * n; j += 4)
            {
                a[i][j] = '.';
                a[i + 1][j] = '.';
                a[i][j + 1] = '.';
                a[i + 1][j + 1] = '.';
            }
        }
        for (ll i = 2; i < 2 * n; i += 4)
        {
            for (ll j = 2; j < 2 * n; j += 4)
            {
                a[i][j] = '#';
                a[i + 1][j] = '#';
                a[i][j + 1] = '#';
                a[i + 1][j + 1] = '#';
            }
        }
        for (ll i = 2; i < 2 * n; i += 4)
        {
            for (ll j = 0; j < 2 * n; j += 4)
            {
                a[i][j] = '.';
                a[i + 1][j] = '.';
                a[i][j + 1] = '.';
                a[i + 1][j + 1] = '.';
            }
        }

        for (ll i = 0; i < 2 * n; i++)
        {
            for (ll j = 0; j < 2 * n; j++)
                cout << a[i][j];
            cout << endl;
        }
    }

    return 0;
}