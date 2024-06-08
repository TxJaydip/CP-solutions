#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl
#define yes1 cout << "YES1" << endl
#define yes2 cout << "YES2" << endl
#define yes3 cout << "YES3" << endl
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
        ll x, y, z;
        cin >> x >> y >> z;

        ll temp = 2 * y - z;
        if (temp >= x && temp % x == 0 && temp)
        {
            yes;
            continue;
        }

        temp = x + (z - x) / 2;
        if (temp >= y && ((z - x) % 2 == 0) && (temp % y == 0) && temp)
        {
            yes;
            continue;
        }

        temp = x + (2 * (y - x));
        // cout << "x: " << x << ", y: " << y << ", z: " << z << ", y-x: " << y - x << ", 2*(y-x)" << 2 * (y - x) << endl;
        // cout << "new_c: " << temp << ", " << (temp >= z) << " " << (temp % z == 0) << " " << (temp != 0) << endl;
        if (temp >= z && (temp % z == 0) && temp)
        {
            yes;
            continue;
        }
        no;
    }
    return 0;
}