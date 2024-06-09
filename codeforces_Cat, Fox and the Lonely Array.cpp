#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll MOD = (7 + (10e9));

string decToBin(ll num)
{
    string str;
    // while (num)
    // {
    //     if (num & 1)
    //         str += '1';
    //     else
    //         str += '0';
    //     num >>= 1;
    // }
    // return str;
    for (int i = 21; i >= 0; i--)
    {
        int k = num >> i;
        if (k & 1)
            str += "1";
        else
            str += "0";
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

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi v;
        iv(v, n);
        ll orOfAll = 0;
        for (auto i : v)
        {
            orOfAll |= i;
        }
        ll j = 0;
        ll flag = 0;
        string sAll = decToBin(orOfAll);
        ll max_length = 0;
        for (ll i = 0; i < 22; i++)
        {
            if (i == 21)
            {
                max_length = 21;
            }
            if (sAll[i] == '1')
            {
                max_length = i;
                break;
            }
        }
        vector<string> vs(n);
        for (ll i = 0; i < n; i++)
        {
            vs[i] = decToBin(v[i]);
        }
        // cout << vs[0].length() << endl;
        // for (auto i : vs)
        // {
        //     cout << i << endl;
        // }

        // cout << "OrOfAll: " << orOfAll << endl;
        // cout << "Max_length: " << max_length << endl;
        ll ans = 1;
        for (ll j = 21; j >= max_length; j--)
        {
            ll cnt = 1;
            for (ll i = 0; i < n; i++)
            {
                if (vs[i][j] == '0')
                {
                    cnt++;
                }
                else
                {
                    ans = max(cnt, ans);
                    cnt = 1;
                }
            }
            if (sAll[j] == '1')
                ans = max(cnt, ans);
        }
        cout << ans << endl;
        // cout << ans << "\n___________________\n"
        //      << endl;
    }
    return 0;
}