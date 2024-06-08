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
        ll a[3];
        for (ll i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        ll cnt = 0;
        ll flag = 0;
        while (true)
        {
            sort(a, a + 3);
            if ((a[1] == 0 && a[2] == 0) || (a[1] == 0 && a[0] == 0 && a[2] % 2 == 0))
            {
                flag = 1;
                break;
            }
            if (a[0] == 0 && a[1] == 0 && a[2] % 2 != 0)
            {
                flag = 2;
                break;
            }
            cnt++;
            a[2]--;
            a[1]--;
        }
        if (flag == 2)
        {
            cout << -1 << endl;
        }
        else if (flag == 1)
        {
            cout << cnt << endl;
        }
        else if (flag == 0)
        {
            cout << "flag" << endl;
        }
    }
    return 0;
}