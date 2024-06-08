#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes sout("YES")
#define no sout("NO")
#define alice sout("ALICE")
#define bob sout("BOB")
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

string decToBin32(ll n)
{
    string ans = "";
    for (ll i = 21; i >= 0; i--)
    {
        ll k = n >> i;
        if (k & 1)
            ans += "1";
        else
            ans += "0";
    }
    return ans;
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
        scanf("%lld", &temp);
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
    cin >> s;
    return;
}

void out(ll &i)
{
    printf("%lld\n", i);
}

void sout(string s)
{
    cout << s << "\n";
}

void aout(vi &v)
{
    for (ll i : v)
    {
        printf("%lld ", i);
    }
    printf("\n");
}

void all(vi &v)
{
    sort(v.begin(), v.end());
    return;
}

int main()
{
    ll t;
    in(t);
    // sout("going to while\n");
    while (t--)
    {
        ll n;
        in(n);
        vi v;
        iv(v, n);
        vector<string> ans;
        for (auto i : v)
        {
            ans.pb(decToBin32(i));
        }
        ll cnt0 = 0;
        ll cnt1 = 0;
        ll flag = 0;
        // sout("BIN:");
        // for (auto i : ans)
        // {
        //     sout(i);
        // }

        for (ll i = 0; i <= 21; i++)
        {
            cnt0 = 0;
            for (ll j = 0; j < n; j++)
            {
                if (ans[j][i] == '0')
                    cnt0++;
            }
            cnt1 = n - cnt0;
            if (cnt1 % 2 && cnt0 % 2)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            no;
        }
        else
        {
            yes;
        }
    }
    return 0;
}