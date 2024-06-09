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
        string s;
        ll n;
        cin >> n;
        cin >> s;
        ll ans = 0;
        for (ll i = 0; i < n - 2;)
        {
            if (i < n - 4)
            {
                if ((s.substr(i, 5)) == "mapie")
                {
                    ans++;
                    i += 5;
                    continue;
                }
            }
            if ((s.substr(i, 3)) == "map" || (s.substr(i, 3)) == "pie")
            {
                ans++;
                i += 3;
                continue;
            }
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}