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
        ll n, m;
        cin >> n >> m;
        char a[n][m];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        ll flag = 0;
        ll wcnt = 0;
        ll bcnt = 0;
        {

            for (ll i = 0; i < n; i++)
            {
                if (a[i][0] == 'W')
                {
                    wcnt++;
                    break;
                }
            }
            for (ll i = 0; i < n; i++)
            {
                if (a[i][m - 1] == 'W')
                {
                    wcnt++;
                    break;
                }
            }
            for (ll i = 0; i < m; i++)
            {
                if (a[0][i] == 'W')
                {
                    wcnt++;
                    break;
                }
            }
            for (ll i = 0; i < m; i++)
            {
                if (a[n - 1][i] == 'W')
                {
                    wcnt++;
                    break;
                }
            }
        }
        //  counting blacks
        {
            for (ll i = 0; i < n; i++)
            {
                if (a[i][0] == 'B')
                {
                    bcnt++;
                    break;
                }
            }
            for (ll i = 0; i < n; i++)
            {
                if (a[i][m - 1] == 'B')
                {
                    bcnt++;
                    break;
                }
            }
            for (ll i = 0; i < m; i++)
            {
                if (a[0][i] == 'B')
                {
                    bcnt++;
                    break;
                }
            }
            for (ll i = 0; i < m; i++)
            {
                if (a[n - 1][i] == 'B')
                {
                    bcnt++;
                    break;
                }
            }
        }
        if (wcnt == 4 || bcnt == 4)
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