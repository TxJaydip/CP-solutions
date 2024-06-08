#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
ll MOD = 1000000007;

void iv(vector<int> &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

// ll fun(vector<int> &v, vi &dp, int n)
// {
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     ll ans = 0;
//     for (auto i : v)
//     {
//         ll curr = n - i;
//         if (curr >= 0)
//         {
//             ll temp = fun(v, dp, curr) % MOD;
//             // ans += fun(v, dp, curr);
//             dp[curr] = temp;
//             ans += temp;
//             ans %= MOD;
//         }
//         else
//             break;
//     }
//     dp[n] = ans;
//     return ans;
// }

// ll fun2(vector<int> &v, unordered_map<int, ll> &dp, int n)
// {

//     if (n < 10000 && dp[n] != 0)
//     {
//         return dp[n];
//     }
//     ll ans = 0;
//     for (auto i : v)
//     {
//         ll curr = n - i;
//         if (curr >= 0)
//         {
//             ll temp = fun2(v, dp, curr) % MOD;
//             // ans += fun(v, dp, curr);
//             if (curr < 10000)
//                 dp[curr] = temp;
//             cout << "dp[" << curr << "]: " << temp << endl;
//             ans += temp;
//             ans %= MOD;
//         }
//         else
//             break;
//     }
//     if (n < 10000)
//         dp[n] = ans;
//     cout << "dp[" << n << "]: " << ans << endl;
//     return ans;
// }

// ll dp[1000001];

// const int MOD = (int)1e9 + 7;

int main()
{
    // int n, x;
    // cin >> n >> x;
    // vi coins(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> coins[i];
    // }
    // dp[0] = 1;
    // for (int weight = 0; weight <= x; weight++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (weight - coins[i - 1] >= 0)
    //         {
    //             dp[weight] += dp[weight - coins[i - 1]];
    //             dp[weight] %= MOD;
    //         }
    //     }
    // }
    // cout << dp[x] << '\n';
    // return 0;

    ll n, x;
    cin >> n >> x;
    vector<int> v;
    iv(v, n);
    // sort(v.begin(), v.end());
    // cout << "After sort\n";
    // unordered_map<int, ll> mp;
    // mp[0] = 1;
    // dp[0] = 1;
    // cout << "\ndp: ";
    // for (auto i : dp)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // ll ans = fun(v, dp, x);

    // cout << "Ans: " << ans << endl;

    vi dp(1000001);
    dp[0] = 1;
    for (int i = 0; i <= x; i++)
    {
        // cout << i << ", ";
        for (auto j : v)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;

    return 0;
}