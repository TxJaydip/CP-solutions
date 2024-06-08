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
        vector<char> s;
        ll temp;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
            {
                s.pb('e');
            }
            else
            {
                s.pb('o');
            }
        }
        ll i = 0;
        ll cnt = 1;
        ll ans = 0;
        // cout << "S: ";
        // for (auto i : s)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        for (ll i = 1; i < n; i++)
        {
            // cout << "Curr: " << s[i] << ", prev: " << s[i - 1] << endl;

            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                ans += cnt - 1;
                cnt = 1;
            }
        }
        ans += cnt - 1;
        cout << ans << endl;
    }
    return 0;
}