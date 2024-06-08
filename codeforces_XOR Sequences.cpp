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
        ll x, y;
        cin >> x >> y;
        string s1 = decToBin(x);
        string s2 = decToBin(y);
        // cout << "------------------------\n";
        // cout << x << ": " << s1 << endl;
        // cout << y << ": " << s2 << endl;
        if (x > y)
        {
            ll i = 0;
            while (i < s2.length() && s1[i] == s2[i])
            {
                i++;
            }
            while (i >= s2.length() && i < s1.length() && s1[i] == '0')
            {
                i++;
            }
            cout << (1ll << i) << endl;
        }
        else
        {
            ll i = 0;
            while (i < s1.length() && s1[i] == s2[i])
            {
                i++;
            }
            while (i >= s1.length() && i < s2.length() && s2[i] == '0')
            {
                i++;
            }
            cout << (1ll << i) << endl;
        }
    }
    return 0;
}