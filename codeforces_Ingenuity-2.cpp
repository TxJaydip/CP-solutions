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

ll fun(ll &Scan, ll &Sflag, string &ans, ll &Sper, ll &Srem)
{
    if (Scan > 0)
    {
        if (Sflag < 2)
        {
            ans += "R";
            Sflag++;
        }
        else
        {
            ans += "H";
            Sflag++;
        }
        if (Sflag == 4)
            Sflag = 0;
        Scan--;
    }
    else
    {
        if (Sper < Srem / 2)
        {
            ans += "R";
            Sper++;
        }
        else
        {
            ans += "H";
        }
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
        string s;
        cin >> s;
        unordered_map<char, int> m;
        m['S'] = 0;
        m['E'] = 0;
        m['W'] = 0;
        m['N'] = 0;
        for (auto i : s)
        {
            m[i]++;
        }
        ll reqR, reqH, Wcan, Ecan, Ncan, Scan;
        ll west, south, north, east;
        west = m['W'];
        east = m['E'];
        south = m['S'];
        north = m['N'];
        if ((n == 2 && (east == 1 || west == 1 || south == 1 || north == 1)) || n % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        if (
            abs(west - east) % 2 == 0 &&
            abs(south - north) % 2 == 0)
        {
            ll Wcan = min(west, east);
            ll Ecan = min(east, west);
            ll Scan = min(south, north);
            ll Ncan = min(north, south);

            ll Eflag = 2, Sflag = 2, Wflag = 0, Nflag = 0;
            ;

            ll Srem = south - Scan;
            ll Nrem = north - Ncan;
            ll Erem = east - Ecan;
            ll Wrem = west - Wcan;

            ll Sper = 0;
            ll Eper = 0;
            ll Wper = 0;
            ll Nper = 0;
            string ans;
            // cout<<
            for (auto i : s)
            {
                switch (i)
                {
                case 'S':
                    fun(Scan, Sflag, ans, Sper, Srem);
                    break;
                case 'W':
                    fun(Wcan, Wflag, ans, Wper, Wrem);
                    break;
                case 'E':
                    fun(Ecan, Eflag, ans, Eper, Erem);
                    break;
                case 'N':
                    fun(Ncan, Nflag, ans, Nper, Nrem);
                    break;
                }
            }
            // cout << s << endl;
            cout << ans << endl;
            // cout << "--------------\n";
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}