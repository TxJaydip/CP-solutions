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
        string x, y;
        cin >> x;
        cin >> y;
        int i = 0;
        while (i < x.length() && x[i] == y[i])
        {
            i++;
        }
        int small;
        if (i < x.length())
        {
            if (x[i] < y[i])
            {
                small = 1;
            }
            else
            {
                small = 2;
            }
        }
        i++;
        if (small == 1)
        {
            for (; i < x.length(); i++)
            {
                if (y[i] > x[i])
                {
                    swap(x[i], y[i]);
                }
            }
        }
        else
        {
            for (; i < x.length(); i++)
            {
                if (y[i] < x[i])
                {
                    swap(x[i], y[i]);
                }
            }
        }

        cout << x << "\n"
             << y << endl;
    }
    return 0;
}