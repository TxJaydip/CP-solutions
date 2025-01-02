#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define mod 7 + 1e9
#define mp map<int, int>

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

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

int binToDec(string str)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        map<int, ll> m;

        ll mfeq = 0;
        ll maxele = -1;

        ll sum2 = 0;

        vi v(n, 0);
        int zerocount = n;
        ll rans = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            // ll rans = 0;
            zerocount--;
            m[y]++;
            if (m[y] > mfeq)
            {
                maxele = y;
                mfeq = m[y];
            }
            else if (m[y] > 1)
            {
                rans -= max(0ll, ((m[y] - 1) * (m[y] - 2) / 2));
                rans += (m[y] * (m[y] - 1) / 2);
            }
            ll pr = (zerocount + mfeq) * (zerocount + mfeq - 1) / 2;

            cout << rans + pr << " ";
        }
        cout << endl;
    }
    return 0;
}