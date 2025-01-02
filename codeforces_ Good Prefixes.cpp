#include "bits/stdc++.h"
using namespace std;

#define ll unsigned long long int
#define pb push_back
#define vi vector<lltow>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define alice cout << "ALICE\n"
#define bob cout << "BOB\n"
#define endl "\n";
ll MOD = (7 + (1e9));
ll MOD2 = 100000037;

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

// void iv(vi &v, int n)
// {
//     ll temp;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> temp;
//         v.pb(temp);
//     }
// }

// void ov(vi &v, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// // }

// void all(vi &v)
// {
//     sort(v.begin(), v.end());
//     return;
// }

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
        vector<unsigned long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> pre(n);
        ll sum = v[0];
        pre[0] = v[0];
        // pre[0] %= MOD2;
        for (int i = 1; i < n; i++)
        {
            pre[i] = v[i] + pre[i - 1];
            // pre[i] %= MOD2;
        }
        vector<ll> maxes(n);
        ll maxi = v[0];
        maxes[0] = v[0];
        for (ll i = 1; i < n; i++)
        {
            maxes[i] = max(maxes[i - 1], v[i]);
        }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (((pre[i] - maxes[i])) == (maxes[i]))
            {
                count++;
            }
        }
        // cout << "pre: ";
        // for (auto i : pre)
        // {
        //     cout << i << " ";
        // }
        // cout << "\nmax: ";
        // for (auto i : maxes)
        // {
        //     cout << i << " ";
        // }
        cout << count << endl;
    }
    return 0;
}

// -----------------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long int
// #define pb push_back
// #define ppb pop_back
// #define vi vector<ll>
// #define vvi vector<vector<int>>
// #define vpi vector<pair<int, int>>
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define mod 7 + 1e9
// #define mp map<int, int>

// ll gcd(ll a, ll b)
// {
//     while (b != 0)
//     {
//         ll temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// void iv(vi &v, ll n)
// {
//     ll temp;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> temp;
//         v.pb(temp);
//     }
// }

// string decToBin(ll num)
// {
//     string str;
//     while (num)
//     {
//         if (num & 1)
//             str += '1';
//         else
//             str += '0';
//         num >>= 1;
//     }
//     return str;
// }

// int binToDec(string str)
// {
//     ll dec_num = 0;
//     ll power = 0;
//     ll n = str.length();
//     for (ll i = n - 1; i >= 0; i--)
//     {
//         if (str[i] == '1')
//         {
//             dec_num += (1 << power);
//         }
//         power++;
//     }
//     return dec_num;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         vi v;
//         iv(v, n);
//         int count = 0;

//         if (v[0] == 0)
//             count = 1;
//         ll maxi = v[0];
//         ll sum = 0;
//         vi prefixsum;
//         for (auto i : v)
//         {
//             sum += i;
//             prefixsum.pb(sum);
//         }

//         for (int i = 1; i < n; i++)
//         {
//             maxi = max(maxi, v[i]);

//             if (prefixsum[i] - maxi == maxi)
//             {
//                 count++;
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }