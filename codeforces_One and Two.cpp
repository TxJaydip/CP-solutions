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
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 2)
                cnt++;
        }
        if (cnt % 2 != 0)
        {
            cout << "-1" << endl;
            continue;
        }
        cnt /= 2;
        ll cnt2 = 0;
        ll ind = 0;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] == 2)
            {
                cnt2++;
            }
            if (cnt2 == cnt)
            {
                ind = i;
                break;
            }
        }
        cout << ind + 1 << endl;
    }
    return 0;
}