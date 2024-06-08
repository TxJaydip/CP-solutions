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
        vi temp;
        ll sum = 0;
        ll gcd;
        ll curr;
        ll num;
        int flag = 0;
        ll mini;
        for (ll i = 1; i <= 100000000; i++)
        {
            if (i == 100000000)
            {
                flag = 1;
                break;
            }
            temp.clear();
            curr = v[0] * i;
            mini = curr;
            gcd = i;
            sum = i;
            ll j = 1;
            temp = {i};
            while (j < n)
            {
                num = ceil((double)curr / (double)v[j]);
                temp.pb(num);
                gcd = __gcd(gcd, num);
                sum += num;
                mini = min(mini, num * v[j]);
                if (gcd > 1 || num == 0)
                {
                    flag = 1;
                    break;
                }
                j++;
            }
            if (flag == 1)
            {
                break;
            }
            if (sum > mini)
            {
                flag = 2;
                break;
            }
        }
        if (flag == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (flag == 2)
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