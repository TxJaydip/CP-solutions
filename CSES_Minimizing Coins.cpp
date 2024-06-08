#include "bits/stdc++.h"
using namespace std;

#define ll int
#define pb push_back
#define vi vector<int>

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

int main()
{
    // ll t;
    ll n, x;
    cin >> n >> x;
    vi v;
    iv(v, n);
    sort(v.begin(), v.end());
    vector<vector<ll>> dp(n, vector<ll>(x + 1, -1));
    for (int i = 0; i < n; i++)
    {
        for (ll j = 0; j <= x; j++)
        {
            if (i == 0)
            {
                if (j % v[i] == 0)
                {
                    dp[i][j] = j / v[i];
                }
                continue;
            }

            if ((j - v[i] < 0) || (dp[i][j - v[i]] == -1))
            {
                dp[i][j] = dp[i - 1][j];
            }

            else if (dp[i - 1][j] == -1)
            {
                dp[i][j] = 1 + dp[i][j - v[i]];
            }

            else
            {
                dp[i][j] = min(
                    dp[i - 1][j],
                    1 + dp[i][j - v[i]]);
            }

            // if (dp[i - 1][j] == -1)
            // {
            //     if (j - v[i] < 0)
            //     {
            //     }
            //     else
            //     {
            //         dp[i][j] = 1 + dp[i][j - v[i]];
            //         if (dp[i][j] == 0)
            //         {
            //             dp[i][j] = dp[i - 1][j];
            //         }
            //     }
            // }
            // else
            // {
            //     if (j - v[i] < 0)
            //     {
            //         dp[i][j] = dp[i - 1][j];
            //     }
            //     else
            //     {
            //         dp[i][j] = min(1 + dp[i][j - v[i]],
            //                        dp[i - 1][j]);
            //     }
            //     if (dp[i][j] == 0)
            //     {
            //         dp[i][j] = dp[i - 1][j];
            //     }
            // }
        }
    }
    // cout << "dp: " << endl;
    // int k = x;
    // for (ll i = 0; i <= k; i++)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //     {

    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n - 1][x] << endl;

    return 0;
}