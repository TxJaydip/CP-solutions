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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vi v(26);
        for (auto i : s)
        {
            v[i - 'a']++;
        }
        vi v2;
        ll odds = 0;
        ll evens = 0;
        for (auto i : v)
        {
            if (i)
            {
                v2.pb(i);
                if (i % 2 == 0)
                    evens++;
                else
                    odds++;
            }
        }
        if (k >= odds - 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}