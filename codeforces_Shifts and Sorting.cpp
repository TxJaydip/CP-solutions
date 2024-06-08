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
        string s;
        cin >> s;
        ll cnt1 = 0;
        ll cnt0 = 0;

        ll i = 0;
        ll flag1 = 0;
        while (s[i] == '0')
            i++;
        ll ans = 0;
        while (true)
        {
            if (i >= s.length())
            {
                break;
            }
            while (s[i] == '1')
            {
                cnt1++;
                i++;
                if (i == s.length())
                {
                    break;
                }
            }
            if (i < s.length())
            {
                cnt0 = 0;
                while (s[i] == '0')
                {
                    cnt0++;
                    i++;
                    if (i == s.length())
                    {
                        ans += (1 + cnt1) * cnt0;
                        break;
                    }
                }
                if (i < s.length())
                {
                    ans += (1 + cnt1) * cnt0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}