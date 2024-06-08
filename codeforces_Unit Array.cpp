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
        ll positive = 0;
        ll negative = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 1)
            {
                positive++;
            }
            else
            {
                negative++;
            }
        }
        if (positive >= negative && negative % 2 == 0)
        {
            cout << 0 << endl;
        }
        else if (positive >= negative && negative % 2 != 0)
        {
            cout << 1 << endl;
        }
        else
        {
            ll cnt = 0;
            while (!(positive >= negative && negative % 2 == 0))
            {
                negative--;
                positive++;
                cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}