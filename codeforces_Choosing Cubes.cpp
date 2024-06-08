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
        ll n, f, k;
        cin >> n >> f >> k;
        vi v;
        iv(v, n);

        if (k == 0)
        {
            no;
            continue;
        }
        if (k == n)
        {
            yes;
            continue;
        }
        ll fav = v[f - 1];
        // cout << "fav: " << fav << ", k : " << k << endl;
        sort(v.rbegin(), v.rend());
        ll i = k;
        ll flag1 = 0;
        ll flag2 = 0;
        while (true)
        {
            if (i == n)
            {
                break;
            }
            if (v[i] == fav)
            {
                flag2 = 1;
                break;
            }
            i++;
        }
        i = 0;
        while (true)
        {
            if (i == k)
            {
                break;
            }
            if (v[i] == fav)
            {
                flag1 = 1;
                break;
            }
            i++;
        }
        // cout << "Sorted: ";
        // for (auto i : v)
        // {
        //     cout << i << " ";
        // }
        // cout << "\nfirst half: " << flag1 << endl;
        // cout << "second half: " << flag2 << endl;

        if (flag1 == 1 && flag2 == 1)
        {
            cout << "MAYBE" << endl;
        }
        else if (flag2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (flag2 == 1)
        {
            cout << "NO" << endl;
        }
        // cout << "\n______________\n";
    }
    return 0;
}