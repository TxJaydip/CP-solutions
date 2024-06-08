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

bool check(vi &v, ll pos)
{
    bool ans = 1;
    if (pos == -1 || pos == v.size() - 2)
    {
        return true;
    }
    if (pos == 0)
    {
        for (ll i = 1; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                return false;
            }
        }
        return true;
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
        if (n == 3)
        {
            yes;
            continue;
        }
        vi b;
        for (int i = 0; i < n - 1; i++)
        {
            b.pb(__gcd(v[i], v[i + 1]));
        }

        ll pos = -1;

        for (ll i = 0; i < b.size() - 1; i++)
        {
            if (b[i] > b[i + 1])
            {
                pos = i;
                break;
            }
        }
        // cout << "Pos: " << pos << endl;
        // cout << "GCDs: ";
        // for (auto i : b)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (pos == -1 || pos == b.size() - 2)
        {
            yes;
            continue;
        }
        vi try1;
        vi gcd1;
        // cout << "pos: " << pos << endl;
        // try1
        try1.clear();
        gcd1.clear();
        ll flag1 = 0;

        for (ll i = 0; i < n; i++)
        {
            if (i != pos)
            {
                try1.pb(v[i]);
            }
        }

        for (ll i = 0; i < try1.size() - 1; i++)
        {
            gcd1.pb(__gcd(try1[i], try1[i + 1]));
        }

        for (ll i = 0; i < gcd1.size() - 1; i++)
        {
            if (gcd1[i] > gcd1[i + 1])
            {
                flag1 = 1;
                break;
            }
        }

        // cout << "try1: ";
        // for (auto i : try1)
        // {
        //     cout << i << " ";
        // }
        // cout << "\ngcd1: ";
        // for (auto i : gcd1)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;

        // try2
        try1.clear();
        gcd1.clear();
        ll flag2 = 0;

        for (ll i = 0; i < n; i++)
        {
            if (i != pos + 1)
            {
                try1.pb(v[i]);
            }
        }

        for (ll i = 0; i < try1.size() - 1; i++)
        {
            gcd1.pb(__gcd(try1[i], try1[i + 1]));
        }

        for (ll i = 0; i < gcd1.size() - 1; i++)
        {
            if (gcd1[i] > gcd1[i + 1])
            {
                flag2 = 1;
                break;
            }
        }

        // cout << "try1: ";
        // for (auto i : try1)
        // {
        //     cout << i << " ";
        // }
        // cout << "\ngcd1: ";
        // for (auto i : gcd1)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;

        // try 3
        try1.clear();
        gcd1.clear();
        ll flag3 = 0;

        for (ll i = 0; i < n; i++)
        {
            if (i != pos + 2)
            {
                try1.pb(v[i]);
            }
        }

        for (ll i = 0; i < try1.size() - 1; i++)
        {
            gcd1.pb(__gcd(try1[i], try1[i + 1]));
        }

        for (ll i = 0; i < gcd1.size() - 1; i++)
        {
            if (gcd1[i] > gcd1[i + 1])
            {
                flag3 = 1;
                break;
            }
        }

        // cout << "try1: ";
        // for (auto i : try1)
        // {
        //     cout << i << " ";
        // }
        // cout << "\ngcd1: ";
        // for (auto i : gcd1)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;

        // final

        if (flag1 == 0 || flag2 == 0 || flag3 == 0)
        {
            yes;
        }
        else
        {
            no;
        }
    }
    return 0;
}