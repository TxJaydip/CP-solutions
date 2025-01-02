#include "bits/stdc++.h"
using namespace std;

#define ll long long int

void print(vector<ll> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    vector<ll> dp(n, 0);
    vector<ll> pref(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        pref[i] = sum;
    }

    // print(pref);
    // return;
    for (int i = 0; i < n; i++)
    {
        if (i - 1 - k >= 0)
            dp[i] = (pref[i] - pref[i - k]) + dp[i - k - 1];
        else if (i - 1 - k == -1)
            dp[i] = pref[i] - pref[i - k];
        else
            dp[i] = pref[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}