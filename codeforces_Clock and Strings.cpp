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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll a1, b1, c1, d1;
        a1 = min(a, b);
        b1 = max(a, b);
        c1 = min(c, d);
        d1 = max(c, d);
        // if(
        //         c1 <
        // )
        vi v;
        for (ll i = a1; i <= b1; i++)
        {
            v.pb(i);
        }
        ll flagSt = 0;
        ll flagEd = 0;
        ll left = c1;
        ll right = d1;
        for (auto i : v)
        {
            if (i == left)
            {
                flagSt = 1;
                break;
            }
        }
        for (auto i : v)
        {
            if (i == right)
            {
                flagEd = 1;
                break;
            }
        }
        if ((flagSt == 1 && flagEd == 1) || (flagSt == 0 && flagEd == 0))
        {
            no;
        }
        else
        {
            yes;
        }
    }
    return 0;
}