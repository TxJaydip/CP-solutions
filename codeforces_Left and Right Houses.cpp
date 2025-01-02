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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l0 = 0, r1 = 0;
        int mid = n / 2;
        for (ll i = 0; i < mid; i++)
        {
            l0 += (s[i] == '0');
        }
        for (ll i = mid; i < n; i++)
        {
            r1 += (s[i] == '1');
        }
        ll r11 = r1, l00 = l0;
        ll diff_left = 0;
        ll ind = mid;
        ll flag = 0;
        for (ll i = mid; i >= 0; i--)
        {
            if (l0 >= round(float(ind) / 2.0) &&
                r1 >= round(float(n - ind) / 2.0))
            {
                flag = 1;
                break;
            }
            if (s[ind - 1] == '1')
            {
                r1++;
            }
            else
            {
                l0--;
            }
            ind--;
        }
        // if (flag == 0)
        // {
        //     ind = INT_MIN;
        // }
        ll ans1 = ind;

        ind = mid;
        l0 = l00;
        r1 = r11;
        flag = 0;

        for (ll i = mid; i < n; i++)
        {
            if (l0 >= round(float(ind) / 2.0) &&
                r1 >= round(float(n - ind) / 2.0))
            {
                flag = 1;
                break;
            }
            if (s[ind] == '1')
            {
                r1--;
            }
            else
            {
                l0++;
            }
            ind++;
        }
        // if (flag == 0)
        // {
        //     ind = INT_MAX;
        // }
        ll ans2 = ind;

        float mid2 = float(n) / 2;
        // cout << "mid: " << mid << ", mid2: " << mid2 << ", ans1: " << ans1 << ", ans2: " << ans2 << endl;
        if (mid2 - ans1 <= ans2 - mid2)
        {
            cout << ans1 << endl;
        }
        else
        {
            cout << ans2 << endl;
        }
        // if (flag == 0)
        // {
        //     // cout << "flag = 0" << endl;
        //     ind++;
        // }
        // cout << s
        //      << ": ans1: "
        //      << ans1
        //      << ", ans2: "
        //      << ans2
        //      << ", r1_initial: "
        //      << r11
        //      << ", l0_initial: "
        //      << l00
        //      << ", r1: "
        //      << r1
        //      << ", l0: "
        //      << l0 << endl;
    }
    return 0;
}