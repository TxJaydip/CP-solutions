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
        ll n2 = n + 1;
        vi b;
        ll temp;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            b.pb(n2 - temp);
        }
        for (auto i : b)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}