#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin >> n;
    // vector<vector<char>> grid(n, vector<char>(n));
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    // cout << "GRid: " << endl;
    // for (auto i : grid)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // vector<vector<ll>> dp(n, vector<ll>(n, 0));
    ll dp[n][n];
    // for (int)
    // cout << "Dp initial: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;
    if (grid[n - 1][n - 1] != '*')
        dp[n - 1][n - 1] = 1;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (grid[n - 1][i] != '*')
        {
            dp[n - 1][i] = 1;
        }
        else
            break;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (grid[i][n - 1] != '*')
        {
            dp[i][n - 1] = 1;
        }
        else
            break;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (grid[i][j] != '*')
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                dp[i][j] %= 1000000007;
            }
        }
    }

    // cout << "Dp final: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    cout << dp[0][0] << endl;

    return 0;
}