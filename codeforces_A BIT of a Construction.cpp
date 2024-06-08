#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

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

ll last11(ll n)
{
    string temp = decToBin(n);
    string s1 = "";
    string s2 = "";
    ll n1, n2;
    for (ll i = 0; i < temp.length(); i++)
    {
        s1 += "1";
    }
    n1 = binToDec(s1);
    s1.pop_back();
    n2 = binToDec(s1);

    if (n1 == n)
    {
        return n;
    }
    else
        return n2;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << k << endl;
            continue;
        }
        ll num = last11(k);
        ll n2 = k - num;
        cout << num << " ";
        cout << n2 << " ";
        for (ll i = 0; i < n - 2; i++)
        {
            cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}