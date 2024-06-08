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
        ll n;
        cin >> n;
        ll st, ed;
        cin >> st >> ed;

        unordered_map<int, unordered_set<int>> mp;
        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            mp[a].insert(b);
            mp[b].insert(a);
        }
        if (st == ed)
        {
            cout << n + 2 << endl;
            continue;
        }
        unordered_set<int> temp1 = mp[st];
        if (temp1.find(ed) != temp1.end())
        {
            cout << n + 3 << endl;
            continue;
        }
        ll cnt = 0;
        ll flag = 0;
        while (true)
        {
            cnt++;
            unordered_set<int> temp3;
            for (auto i : temp1)
            {
                for (auto j : mp[i])
                {
                    temp3.insert(j);
                }
            }
            if (temp3.find(ed) != temp3.end())
            {
                flag = 1;
                cout << n + 2 + cnt << endl;
                break;
            }
            temp1 = temp3;
        }
    }
    return 0;
}