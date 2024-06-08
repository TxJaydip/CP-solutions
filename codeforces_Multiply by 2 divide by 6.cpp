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

ll digitsSum(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll flag = 0;
        ll cnt = 0;
        while (true)
        {
            if (n == 1)
            {
                break;
            }
            if (n % 6 == 0)
            {
                n /= 6;
                cnt++;
            }
            else if (digitsSum(n) % 3 == 0)
            {
                n *= 2;
                cnt++;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << cnt << endl;
        }
    }
    return 0;
}