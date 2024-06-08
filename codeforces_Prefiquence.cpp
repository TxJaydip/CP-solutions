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
        ll n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        ll j = 0;
        ll i;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        // cout << "a: " << a << endl;
        // cout << "b: " << b << endl;
        while (!a.empty() && !b.empty())
        {
            if (a.back() == b.back())
            {
                a.pop_back();
                b.pop_back();
            }
            else
            {
                b.pop_back();
            }
        }
        // cout<<a.length()
        cout << n - a.length() << endl;
    }
    return 0;
}