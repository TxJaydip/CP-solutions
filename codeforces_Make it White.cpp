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
        string s;
        cin >> n;
        cin >> s;
        ll l = 0;
        ll r = n - 1;
        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                l = i;
                break;
            }
            else if (i == n - 1)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            for (ll i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'B')
                {
                    r = i;
                    break;
                }
            }
            cout << r - l + 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
