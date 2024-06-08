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
        ll lcm1 = v[0];
        for (ll i = 1; i < n; i++)
        {
            lcm1 = ((lcm1 * v[i])) / (__gcd(lcm1, v[i]));
        }
        vi temp;
        for (ll i = 0; i < n; i++)
        {
            temp.pb(lcm1 / v[i]);
        }
        ll sum = 0;
        for (auto i : temp)
        {
            sum += i;
        }
        ll mini = temp[0] * v[0];
        for (ll i = 1; i < n; i++)
        {
            mini = min(mini, v[i] * temp[i]);
        }
        if (mini <= sum)
        {
            cout << -1 << endl;
        }
        else
        {
            for (auto i : temp)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}