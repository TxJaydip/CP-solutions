#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define vi vector<int>
// ll      MOD = 1000000007;
#define MOD 1000000007

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
}

int main()
{
    ll n;
    ll x;
    // vi v;
    scanf("%lld %lld", &n, &x);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    ll dp[x + 1] = {0};
    dp[0] = 1;
    for (int coin = 0; coin < n; coin++)
    {
        for (int i = 0; i <= x; i++)
        {
            if (i - v[coin] >= 0)
            {
                dp[i] += dp[i - v[coin]];
                dp[i] %= MOD;
            }
        }
    }
    // for (auto i : dp)
    // {
    //     cout << i << " ";
    // }
    cout << dp[x] << endl;

    return 0;
}