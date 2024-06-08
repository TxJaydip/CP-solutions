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
        ll cnt2 = 0;
        ll flag = 0;
        ll i1 = s.length() - 1;
        while (i1 > 0 && s[i1] != '0')
        {
            i1--;
            cnt1++;
        }
        // if (i1 != s.length() - 1)
        //     cnt1--;
        if (s[i1] == '0')
            i1--;
        while (i1 >= 0 && !(s[i1] == '0' || s[i1] == '5'))
        {
            i1--;
            cnt1++;
        }

        ll i2 = s.length() - 1;
        while (i2 > 0 && !(s[i2] == '5'))
        {
            i2--;
            cnt2++;
        }
        // if (i2 != s.length() - 1)
        //     cnt2--;
        if (s[i2] == '5')
            i2--;
        while (i2 >= 0 && !(s[i2] == '7' || s[i2] == '2'))
        {
            i2--;
            cnt2++;
        }
        // cout << "Num: " << s << endl;
        // cout << "Cnt1: " << cnt1 << ", Cnt2: " << cnt2 << endl;
        // cout << "i1: " << i1 << ", i2: " << i2 << endl;
        cout << min(cnt1, cnt2) << endl;
    }

    return 0;
}