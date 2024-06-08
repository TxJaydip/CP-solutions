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

// bool fun(vector<int> &m1, vector<int> &m2)
// {
//     if (
//         m1[])
// }

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
        ll ans = 0;
        // vector<vector<int>> mat;
        // for (ll i = 0; i < n - 2; i++)
        // {
        //     mat.pb({v[i], v[i + 1], v[i + 2]});
        //     // mat.pb(temp);
        // }

        for (ll i = 0; i < n - 3; i++)
        {
            for (ll j = i + 1; j < n - 2; j++)
            {
                if (
                    (v[i] == v[j] && v[i + 1] == v[j + 1] && v[i + 2] != v[j + 2]) ||
                    (v[i] == v[j] && v[i + 1] != v[j + 1] && v[i + 2] == v[j + 2]) ||
                    (v[i] != v[j] && v[i + 1] == v[j + 1] && v[i + 2] == v[j + 2]))
                {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}