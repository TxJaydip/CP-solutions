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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        long long unsigned int k;
        cin >> x >> y >> z >> k;
        // if (x * y * z < k)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // if (x * y * z == k)
        // {
        //     cout << 1 << endl;
        //     continue;
        // }
        // vi primes = primeFactors(k);
        // ll mini = min(x, min(y, z));
        // ll maxi = max(x, max(y, z));
        // ll mid;
        // if (x != mini && x != maxi)
        // {
        //     mid = x;
        // }
        // else if (y != mini && y != maxi)
        // {
        //     mid = y;
        // }
        // else
        // {
        //     mid = z;
        // }

        // if (primes[0] > mini)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }

        ll ans = 0;
        for (ll i = 1; i <= x; i++)
        {
            for (ll j = 1; j <= y; j++)
            {
                if (k % (i * j) == 0 && (k / (i * j)) <= z)
                {
                    ans = max(ans, (x - i + 1) * (y - j + 1) * (1 + z - (k / (i * j))));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}