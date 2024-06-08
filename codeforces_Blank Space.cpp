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
        bool temp;
        ll cnt = 0;
        ll max = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == 0)
            {
                cnt++;
            }
            else
            {
                if (cnt > max)
                    max = cnt;
                cnt = 0;
            }
        }
        if (cnt > max)
            max = cnt;
        cout << max << endl;
    }
    return 0;
}