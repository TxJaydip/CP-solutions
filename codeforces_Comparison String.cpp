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
        string s;
        cin >> s;

        ll max_l = 0;
        ll max_r = 0;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                cnt++;
            }
            else
            {
                if (cnt > max_l)
                    max_l = cnt;
                cnt = 0;
            }
        }
        if (cnt > max_l)
            max_l = cnt;

        cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '>')
            {
                cnt++;
            }
            else
            {
                if (cnt > max_r)
                    max_r = cnt;
                cnt = 0;
            }
        }
        if (cnt > max_r)
            max_r = cnt;

        cout << max(max_l, max_r) + 1 << endl;
    }
    return 0;
}