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
        string s;
        cin >> s;
        string ans;
        cin >> ans;
        string s2 = "";
        for (auto i : s)
        {
            s2 += "0";
        }
        int p2 = ans.length() - 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ans[p2])
            {
                s2[i] = s[i];
                p2--;
            }
        }
        if (p2 >= 0)
        {
            // cout << 1;
            no;
            continue;
        }
        vi cnt(26, 0);
        unordered_map<char, int> mp;
        for (auto i : ans)
        {
            mp[i]++;
        }
        int flag = 0;
        // for(auto i:cnt)
        // cout << "s: " << s << "\ns2:" << s2 << "\n---------" << endl;
        for (int i = s.length(); i >= 0; i--)
        {
            // cout << "char: " << s[i] << endl;
            if (s2[i] == '0' && mp[s[i]] > 0)
            {
                flag = 1;
                break;
            }
            if (s2[i] == s[i])
            {
                mp[s[i]]--;
            }
        }
        if (flag)
        {
            no;
        }
        else
            yes;
    }
    return 0;
}