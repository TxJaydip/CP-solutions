#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
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
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << max(v[1] - v[0], v[0] - v[1]) << endl;
            continue;
        }
        ll max1 = v[n - 1] - v[0];
        ll max2 = v[1] - v[0];
        ll max3 = v[n - 1] - v[n - 2];
        for (int i = 0; i < n - 1; i++)
        {
            max1 = max(max1, v[i] - v[i + 1]);
        }

        for (int i = 2; i < n; i++)
        {
            max2 = max(max2, v[i] - v[0]);
        }

        for (ll i = 0; i < n - 2; i++)
        {
            max3 = max(max3, v[n - 1] - v[i]);
        }
        cout << max(max1, max(max2, max3)) << endl;
    }
    return 0;
}