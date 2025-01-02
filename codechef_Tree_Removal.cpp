#include "bits/stdc++.h"
using namespace std;

#define ll long long unsigned int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define alice cout << "ALICE\n"
#define bob cout << "BOB\n"
#define endl "\n";
ll MOD = (7 + (1e9));
ll maxVal = 1000000000000000;

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

vector<ll> primeFactors(ll n)
{
    vector<ll> primes;
    while (n % 2 == 0)
    {
        primes.pb(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primes.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        primes.pb(n);
    return primes;
}

void ovs(set<int> s, int size)
{
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi vert;
        iv(vert, n);
        int temp1, temp2;

        map<int, set<int>> mp;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> temp1;
            cin >> temp2;
            mp[temp1].insert(temp2);
        }
        cout << "creating 0s" << endl;
        for (int i = 1; i <= n; i++)
        {
            if (!mp[i].size())
            {
                cout << "in if" << endl;
                mp[i].insert(0);
            }
        }

        map<int, vector<int>> mp2;
        for (auto i : mp)
        {
            for (auto j : i.second)
            {
                mp2[j].pb(i.first);
            }
        }

        cout << "mp: " << endl;
        for (auto i : mp)
        {
            cout << i.first << ": ";
            ovs(i.second, i.second.size());
        }

        cout << "mp2: " << endl;
        for (auto i : mp2)
        {
        }

        vi ans;
        if (mp2[0].size())
        {
            while (mp2[0].size())
            {
                ll last = mp2[0].back();
                ans.pb(last);
                mp[mp2[last].front()].erase(last);
                mp2[last].clear();
                if (mp[mp2[last].front()].size())
                {
                    mp2[0].pb(mp2[mp2[last].front()].front());
                }
            }
        }
        cout << "Size: " << ans.size() << endl;
        ov(ans, ans.size());

        // vpi edges(n-1);
        // for(ll i = 0;i<n-1;i++)
        // {
        //     cin >> edges[i].first>>edges[i].second;
        // }

        // for(auto i:edges)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
    }
    return 0;
}