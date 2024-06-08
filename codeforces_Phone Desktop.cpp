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

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        float x, y;
        cin >> x >> y;
        // ll mini;
        ll rem;
        float mini = ceil(y / 2);
        if (int(y) % 2 == 0)
        {
            rem = 7 * mini;
        }
        else
        {
            rem = ((mini - 1) * 7) + 11;
        }

        if (x > rem)
        {
            ll extra = (x - rem);
            mini += ceil(float(extra) / 15.0);
        }
        cout << int(mini) << endl;
    }
    return 0;
}