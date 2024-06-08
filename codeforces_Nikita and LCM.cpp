#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<ll>>
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

ll arrayLcm(vi &v)
{
    if (v.size() == 0)
    {
        return 0;
    }
    ll ans = v[0];
    for (auto i : v)
    {
        ans = lcm(ans, i);
    }
    return ans;
}

bool find1(vi &v, ll val)
{
    for (auto i : v)
    {
        if (i == val)
        {
            return true;
        }
    }
    return false;
}

ll ans = 0;

void fun(vector<vector<int>> &dp, vector<ll> &v, ll index, vector<ll> temp)
{
    ll currLcm = arrayLcm(temp);
    // cout << "temp: ";
    // for (auto i : temp)
    // {
    //     cout << i << ",";
    // }
    // cout << endl;
    // cout << "currLCM: " << currLcm << ", currLength: " << temp.size() << endl;
    // // v.find(currLcm);
    // ;
    if (!binary_search(v.begin(), v.end(), currLcm))
    {
        ll sz = temp.size();
        ans = max(ans, sz); 
    }
    if (index == v.size())
    {
        return;
    }
    temp.pb(v[index]);
    fun(dp, v, index + 1, temp);
    temp.pop_back();
    fun(dp, v, index + 1, temp);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi v;
        iv(v, n);
        // ll ans = 0;
        ans = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        ll index = 0;
        // ll ans = 0;
        vector<ll> temp;
        sort(v.begin(), v.end());
        // cout << "before fun" << endl;
        fun(dp, v, index, temp);
        cout << ans << endl;
        // cout << "hello";
    }
    return 0;
}