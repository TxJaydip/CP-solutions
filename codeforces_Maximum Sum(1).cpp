#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define alice cout << "ALICE\n"
#define bob cout << "BOB\n"
#define endl "\n";
ll MOD = (7 + (1e9));

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

void iv(vi &v, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

void ov(vi &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void all(vi &v)
{
    sort(v.begin(), v.end());
    return;
}

ll pow11(ll n, ll n2)
{
    ll ans = 1;
    while (n2--)
    {
        ans *= n;
        ans %= MOD;
    }
    return ans;
}

ll mul(ll a, ll b)
{
    while (b--)
    {
        a += a;
        a %= MOD;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> dp(n);
        dp[0] = v[0];
        for (ll i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + v[i], v[i]);
        }
        // cout << "vi: ";
        // // ov()
        // cout << "dp: ";
        // ov(dp, n);
        // cout << "max: " << *max_element(dp.begin(), dp.end());
        ll ans = *max_element(dp.begin(), dp.end());
        if (ans < 0)
        {
            ans = 0;
            for (auto i : v)
            {
                ans += i;
                ans %= MOD;
            }
            // if(ans<0)
            ans = abs(ans);
            ans %= MOD;
            ans = MOD - ans;
            cout << ans << endl;
            continue;
        }
        else
        {
            ll sum = 0;
            for (auto i : v)
            {
                sum += i;
                sum %= MOD;
            }
            for (ll i = 0; i < k; i++)
            {
                sum += mul(pow11(1ll * 2, i), ans);
                sum %= MOD;
            }
            if (sum < 0)
            {
                sum = abs(sum);
                sum %= MOD;
                sum = MOD - sum;
                // cout << ans << endl;
            }
            cout << sum << endl;
        }
    }
    return 0;
}