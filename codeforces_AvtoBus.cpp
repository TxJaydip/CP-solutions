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
        ll n;
        cin >> n;
        if (n == 2 || n % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }
        ll min = 0;
        ll max = 0;
        ll flag_min = 0;
        ll flag_max = 0;
        if (n == 4 || n == 6)
        {
            min = 1;
            max = 1;
            flag_min = 1;
            flag_max = 1;
            cout << min << " " << max << endl;
            continue;
        }
        if (n == 8)
        {
            min = 2;
            max = 2;
            flag_min = 1;
            flag_max = 1;
            cout << min << " " << max << endl;
            continue;
        }

        if (n % 4 == 0)
        {
            max = n / 4;
            flag_max = 1;
        }
        if (n % 6 == 0)
        {
            min = n / 6;
            flag_min = 1;
        }
        if (flag_max == 0)
        {
            if ((n - 6) % 4 == 0)
            {
                max = 1 + (n - 6) / 4;
            }
        }
        if (flag_min == 0)
        {
            if ((n - 4) % 6 == 0)
            {
                min = 1 + (n - 4) / 6;
            }
            else if ((n - 8) % 6 == 0)
            {
                min = 2 + (n - 8) / 6;
            }
        }
        cout << min << " " << max << endl;
    }
    return 0;
}