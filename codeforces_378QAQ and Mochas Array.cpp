#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
        ll mini = LLONG_MAX;
        ll mini2 = LLONG_MAX;

        sort(v.begin(), v.end());
        mini = v[0];
        ll j = 1;
        while (j < n && v[j] % v[j - 1] == 0)
        {
            j++;
        }
        if (j == n)
        {
            yes;
            continue;
        }
        mini2 = v[j];
        // cout << mini << " " << mini2 << endl;
        ll flag = 0;
        for (auto i : v)
        {
            if (i % mini != 0 && i % mini2 != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            yes;
        }
        else
            no;
    }
    return 0;
}