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
        // cout << "T: " << t << endl;
        ll n, k;
        cin >> n >> k;
        vi v(n);
        k -= 1;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll val = v[k];
        ll cal1 = 0;
        ll cal2 = 0;
        // cal1

        swap(v[0], v[k]);

        for (ll i = 1; i < n; i++)
        {
            if (v[i] < val)
            {
                cal1++;
            }
            else
                break;
        }

        swap(v[0], v[k]);

        // cal2

        ll maxK = 0;
        ll indexK = 0;
        ll maxKK = 0;
        for (ll i = 0; i < k; i++)
        {
            if (v[i] > val)
            {
                maxK = v[i];
                indexK = i;
                break;
            }
        }
        for (ll i = 0; i < indexK; i++)
        {
            if (v[i] > maxKK)
            {
                maxKK = v[i];
            }
        }

        if (maxKK < val && maxK > val)
        {
            swap(v[indexK], v[k]);

            for (ll i = indexK + 1; i < n; i++)
            {
                if (v[i] < val)
                {
                    cal2++;
                }
                else
                    break;
            }
            if (indexK != 0 && v[indexK - 1] < val)
            {
                cal2++;
            }

            swap(v[indexK], v[k]);
        }

        cout << max(cal1, cal2) << endl;
        // cout << "T: " << t << endl;
    }
    // cout << "Out of while, T: " << t << endl;
    return 0;
}