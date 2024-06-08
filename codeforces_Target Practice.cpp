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
        vector<string> v(10);
        for (ll i = 0; i < 10; i++)
        {
            cin >> v[i];
        }
        ll ans = 0;
        for (ll i = 0; i < 10; i++)
        {
            for (ll j = 0; j < 10; j++)
            {
                if (v[i][j] == 'X')
                {
                    if (i == 0 || i == 9 || j == 0 || j == 9)
                        ans += 1;
                    else if (i == 1 || i == 8 || j == 1 || j == 8)
                        ans += 2;
                    else if (i == 2 || i == 7 || j == 2 || j == 7)
                        ans += 3;
                    else if (i == 3 || i == 6 || j == 3 || j == 6)
                        ans += 4;
                    else if (i == 5 || i == 5 || j == 4 || j == 5)
                        ans += 5;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}