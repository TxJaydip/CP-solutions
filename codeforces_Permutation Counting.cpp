#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define vpi vector<pair<ll, ll>>
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

bool pairComp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second > b.second;
}

bool pairCompFirst(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.second;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vpi v;
        pair<ll, ll> temp;
        for (ll i = 1; i <= n; i++)
        {
            cin >> temp.second;
            temp.first = i;
            v.pb(temp);
        }
        sort(v.begin(), v.end(), pairComp);

        for (ll i = 0; i < n; i++)
        {
            if(v[0].second == v[n-1].second)
            {
                break;
            }
            ll j = 1;
            while(v[j].second == v[i].second && j<=k)
            {
                j++;
            }
            

        }
    }
    return 0;
}