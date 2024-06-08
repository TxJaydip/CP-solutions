#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define alice sout("ALICE")
#define bob sout("BOB")
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

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

void in(ll &i)
{
    ll temp;
    scanf("%lld", &temp);
    i = temp;
    return;
}

void sin(string &s)
{
    string s1;
    scanf("%s", s1);
    s = s1;
    return;
}

void out(ll &i)
{
    printf("%lld\n", i);
}

void sout(string &s)
{
    printf("%s\n", s);
}

void aout(vi v)
{
    for (auto i : v)
    {
        printf("%lld ", i);
    }
    printf("\n");
}

void all(vi v)
{
    sort(v.begin(), v.end());
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi x;
        vi p;
        iv(x, n);
        iv(p, n);

        vector<bool> prefix(n - 1);
        vector<bool> suffix(n - 1);
        for (ll i = 0; i < n - 1; i++)
        {
            if (x[i + 1] - x[i] <= p[i])
            {
                prefix[i] = 1;
            }
            else
            {
                prefix[i] = 0;
            }
        }
        for (ll i = n - 1; i > 0; i--)
        {
            if (x[i] - x[i - 1] <= p[i])
            {
                suffix[i] = 1;
            }
            else
            {
                suffix[i] = 0;
            }
        }
        vector<bool> answer(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            answer[i] = prefix[i] | suffix[i];
        }

        ll flag = 0;
        for (auto i : answer)
        {
            if (!i)
            {
                flag++;
            }
        }
        if (flag <= 1)
        {
            yes;
        }
        else
            no;
    }
    return 0;
}