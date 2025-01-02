#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v;
        iv(v, n);
        if (n == 2 && v[0] != v[1])
        {
            cout << 1 << endl;
            continue;
        }
        ll left = -1;
        ll right = -1;

        for (ll i = 0; i < n; i++)
        {
            if (v[i] != v[0])
            {
                left = i;
                break;
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            if (v[i] != v[n - 1])
            {
                right = n - i - 1;
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (v[i] != v[n - 1])
            {
                left = min(left, i);
                break;
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            if (v[i] != v[0])
            {
                right = min(right, n - i - 1);
            }
        }
        int diff = INT_MAX;
        int curr_diff = diff;
        int j = 0;
        for (int i = 0; i < n;)
        {
            if (v[i] != v[0])
            {
                j = i;
                i++;
                while (i < n && v[i] == v[0])
                {
                    i++;
                }
                if (i < n)
                {
                    curr_diff = i - j - 1;
                    diff = min(diff, curr_diff);
                }
            }
            else
                i++;
        }
        left = min(left, 1ll * diff);
        if (left == -1 || right == -1)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            cout << min(left, right) << endl;
        }
        // vi dp(n);
        // dp[0] = 1;
        // for(int i = 1;i<n;i++)
        // {
        //     if(v[i] == v[i-1])
        //     {
        //         dp[i] = dp[i-1]+1;
        //     }
        //     else if(i != 1 && v[i] == v[i-2])
        //     {
        //         dp[i] = dp[i-2]+2;
        //     }
        //     else
        //     {
        //         dp[i] = 1;
        //     }
        // }

        // cout<<
    }
    return 0;
}