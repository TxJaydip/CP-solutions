#include "bits/stdc++.h"
using namespace std;

#define ll long long int

// void solve()
// {
//     ll y;
//     cin >> y;
//     // for (auto i : dp)
//     // {
//     //     cout << i << " ";
//     // }
//     cout << dp[y] << endl;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    ll MOD = 998244353ll;

    unordered_map<ll, ll> scoresOfpowersOf2;
    vector<ll> scores2;
    vector<ll> dp((1 + (4e6)), 0);

    scoresOfpowersOf2[2] = 0;
    scoresOfpowersOf2[4] = 4;
    scoresOfpowersOf2[8] = 16;

    scores2 = {4, 16};
    ll num = 16;
    ll temp = 0;
    while (temp < (4e6))
    {
        temp = num + 2 * (scoresOfpowersOf2[num / 2]);
        scoresOfpowersOf2[num] = temp;
        scores2.push_back(temp);
        num *= 2;
    }

    dp[0] = 1;
    for (int i = 0; i < scores2.size(); i++)
        for (ll s = scores2[i]; s <= 4e6; s += 4)
            dp[s] = (dp[s] + dp[s - scores2[i]]) % MOD;

    ll yy;
    while (t--)
    {
        cin >> yy;
        cout << dp[yy] << endl;
        // solve();
    }
    return 0;
}