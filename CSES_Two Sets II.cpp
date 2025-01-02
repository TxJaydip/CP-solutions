#include "bits/stdc++.h"
using namespace std;

void funct(int, int, int, int &, vector<vector<int>> &dp);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    if (n * (n + 1) / 2 % 2 == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        // vector<int> v1;
        // vector<int> v2;
        int ans = 0;
        int sum1 = 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        dp[0][0] = 1;

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                
            }
        }

        funct(n, 1, sum1, ans, dp);

        cout << ans / 2 << endl;
    }

    return 0;
}

void funct(int n, int ind, int sum1, int &ans, vector<vector<int>> &dp)
{
    // cout << "s1: " << sum1 << ", n - s1: " << (n - sum1) << endl;
    if (ind > n)
    {
        // if (sum1 == ((n * (n + 1) / 2) - sum1))
        // {
        //     ans++;
        // }
        if (sum1 == (n * (n + 1) / 4))
        {
            ans++;
        }
        return;
    }
    funct(n, ind + 1, sum1 + ind, ans, dp);
    funct(n, ind + 1, sum1, ans, dp);
}
