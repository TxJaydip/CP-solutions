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
        ll k, q;
        cin >> k >> q;
        vi n(q);
        vi a(k);
        ll temp = 0;
        ll min1 = 0;
        for (ll i = 0; i < k; i++)
        {
            cin >> temp;
            if (i == 0)
            {
                min1 = temp;
            }
        }
        for (ll i = 0; i < q; i++)
        {
            cin >> temp;
            if (min1 > temp)
                cout << temp << " ";
            else
                cout << min1 - 1 << " ";
        }
        cout << endl;
    }
    return 0;
}