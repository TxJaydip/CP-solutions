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
        int n, k1;
        cin >> n >> k1;
        int k = 2 * k1;

        vi a;
        iv(a, 2 * n);
        vi count(n + 1);
        for (int i = 0; i < n; i++)
            count[a[i]]++;

        vi g0;
        vi g1;
        vi g2;
        for (int i = 1; i <= n; i++)
        {
            if (count[i] == 0)
                g0.push_back(i);
            else if (count[i] == 1)
                g1.push_back(i);
            else
                g2.push_back(i);
        }

        int v = 0;
        for (auto x : g2)
        {
            if (v < k)
            {
                v += 2;
                cout << x << " " << x << " ";
            }
        }
        for (auto x : g1)
        {
            if (v < k)
            {
                v++;
                cout << x << " ";
            }
        }
        cout << endl;

        v = 0;
        for (auto x : g0)
        {
            if (v < k)
            {
                v += 2;
                cout << x << " " << x << " ";
            }
        }
        for (auto x : g1)
        {
            if (v < k)
            {
                v++;
                cout << x << " ";
            }
        }
        cout << endl;
    }
    return 0;
}