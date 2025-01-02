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

ll cnt1 = 0;
ll cnt2 = 0;
ll cnt3 = 0;

ll max(ll a, ll b)
{
    if (a > b)
    {
        cnt1++;
        return a;
    }
    return b;
}

ll min(ll a, ll b)
{
    if (a < b)
    {
        cnt2++;
        return a;
    }
    return b;
}

ll abs1(ll n)
{
    if (n < 0)
    {
        cnt3++;
        n *= -1;
        return n;
    }
    return n;
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
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll maxi = 0;
        ll mini = 0;
        ll temp, temp1, temp2;
        cnt1 = 0;
        cnt2 = 0;
        cnt3 = 0;
        for (int i = 0; i < n; i++)
        {
            temp = v[i];
            temp1 = maxi;
            temp1 += temp;

            temp2 = mini;
            temp2 += temp;

            maxi = max(max(temp1, temp2), (max(abs1(temp1), abs1(temp2))));
            mini = min(min(temp1, temp2), (min(abs1(temp1), abs1(temp2))));

            cout << "max: " << maxi << ", mini: " << mini << endl;
        }
        // mini = abs(mini);

        cout << "cnt1: " << cnt2 << ", cnt2: " << cnt2 << ", cnt3: " << cnt3 << endl;
        cout << "maxi: " << maxi << ", mini: " << mini << endl;
        cout << "------------------\n";

        // cout << max(ans, abs(plus - minus)) << endl;
    }
    return 0;
}