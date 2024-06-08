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
        ll flag = 0;
        vi v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i != 0 && v[i] == v[i - 1])
                flag++;
        }
        if (flag == n - 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            sort(v.rbegin(), v.rend());

            if (v[0] == v[1])
            {
                ll i = 0;
                while (v[i] == v[i + 1])
                {
                    i++;
                }
                i++;
                swap(v[i], v[0]);
            }
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}