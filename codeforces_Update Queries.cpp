#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define alice cout << "ALICE\n"
#define bob cout << "BOB\n"
#define endl "\n";
ll MOD = (7 + (1e9));

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

void iv(vi &v, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

void ov(vi &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void all(vi &v)
{
    sort(v.begin(), v.end());
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vi v1;
        iv(v1, m);
        string c;
        cin >> c;
        all(v1);
        map<char, int> mp;
        for (auto i : c)
        {
            mp[i]++;
        }
        set<char> st;
        for (auto i : c)
        {
            st.insert(i);
        }

        set<int> v2;
        for (auto i : v1)
        {
            v2.insert(i);
        }

        vi v;
        for (auto i : v2)
        {
            v.pb(i);
        }

        int ind = 0;
        // cout << "set: ";
        for (auto i : st)
        {
            // cout << i << " ";
            for (int j = 0; j < mp[i]; j++)
            {
                if (ind >= v.size())
                {
                    break;
                }
                s[v[ind] - 1] = i;
                ind++;
            }
            if (ind >= v.size())
            {
                break;
            }
        }
        // cout << "\nv: ";
        // for (auto i : v)
        // {
        //     cout << i << " ";
        // }

        cout << s << endl;
    }
    return 0;
}