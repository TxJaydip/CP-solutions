#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll MOD = 1000000007;
ll MOD2 = 7 + (10e9);

string decToBin(ll num)
{
    string str;
    while (num)
    {
        if (num & 1)
            str += '1';
        else
            str += '0';
        num >>= 1;
    }
    return str;
}

ll binToDec(string str)
{
    ll dec_num = 0;
    ll power = 0;
    ll n = str.length();
    for (ll i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            dec_num += (1 << power);
        }
        power++;
    }
    return dec_num;
}

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

ll fun(vector<ll> &dp, ll curr, ll n)
{
    if (dp[curr] != -1)
    {
        return dp[curr];
    }
    ll ans1, ans2, ans3, ans4, ans5, ans6;
    ans1 = fun(dp, curr - 1, n);
    dp[curr - 1] = ans1;

    ans2 = fun(dp, curr - 2, n);
    dp[curr - 2] = ans2;

    ans3 = fun(dp, curr - 3, n);
    dp[curr - 3] = ans3;

    ans4 = fun(dp, curr - 4, n);
    dp[curr - 4] = ans4;

    ans5 = fun(dp, curr - 5, n);
    dp[curr - 5] = ans5;

    ans6 = fun(dp, curr - 6, n);
    dp[curr - 6] = ans6;
    // ll answer = ans1 + ans2 + ans3 + ans4 + ans5 + ans6;
    ll answer = (ans1 % MOD) + (ans2 % MOD) + (ans3 % MOD) + (ans4 % MOD) + (ans5 % MOD) + (ans6 % MOD);
    answer %= MOD;
    if (dp[curr] == -1)
    {
        dp[curr] = answer;
    }
    return answer;
}

int main()
{
    ll n;
    cin >> n;
    ll ans;
    ll size = max(n + 1, 1ll * 7);
    vector<ll> dp(size, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    ll num = n;

    ans = fun(dp, num, n);
    // cout << "Answer: ";
    cout << ans << endl;
    // cout << "number: " << 1000000007 << endl;
    // cout << "10e9+7: " << 1ll * (7 + (10e9)) << endl;

    return 0;
}