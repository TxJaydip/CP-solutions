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
        vi a, a2;
        iv(a, n);
        a2 = a;
        vi b;
        iv(b, n);
        ll m;
        cin >> m;
        vi d;
        iv(d, m);

        map<int, int> mp;
        // mp.reserve(4096);
        // mp.max_load_factor(0.25);
        for (auto i : d)
        {
            mp[i]++;
        }

        bool flag = 0;
        ll last = b[0];
        bool lastFlag = 0;
        // cout << "n: " << n << endl;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (mp[b[i]])
                {
                    // cout << "last : " << b[i] << ", i: " << i << endl;
                    lastFlag = 1;
                    last = b[i];
                    mp[b[i]]--;
                    a2[i] = b[i];
                }
                else
                {
                    flag = 1;
                    // cout << "flag 1 i else\n";
                    break;
                }
            }
        }
        // cout << "b: ";
        // for (auto i : b)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << "last: " << last << endl;
        // cout << "d[end]: " << d[m - 1] << endl;
        int flag2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a2[i] == b[i] && d[m - 1] == a2[i])
            {
                flag2 = 1;
                break;
            }
        }
        if (!flag && flag2)
        {
            yes;
        }
        else
            no;
    }
    return 0;
}