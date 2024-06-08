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
        ll n, x0;
        cin >> x0 >> n;
        ll div = n / 4;
        ll rem = n % 4;
        ll curr = x0;
        ll addn = n - rem + 1;
        // cout << "Curr: " << curr << endl;
        // cout << "Rem: " << rem << endl;
        // cout << "Addn: " << addn << endl;

        while (rem--)
        {
            if (curr % 2 == 0)
            {
                curr -= addn;
            }
            else
            {
                curr += addn;
            }
            addn++;
        }
        cout << curr << endl;
    }
    return 0;
}