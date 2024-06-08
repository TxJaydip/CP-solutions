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
        int temp, prev;
        ll diff = 0;
        ll max = INT_MAX;
        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (flag)
                continue;
            if (i == 0)
                prev = temp;
            if (i != 0)
            {
                diff = temp - prev;
                if (diff < 0)
                    flag = 1;
                prev = temp;
                if (diff < max)
                    max = diff;
            }
            // cout << "Temp: " << temp << ", prev: " << prev << endl;
        }
        if (flag)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            cout << 1 + max / 2 << endl;
        }
    }
    return 0;
}