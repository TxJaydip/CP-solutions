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
    reverse(str.begin(), str.end());
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

bool compare(string s1, string s2, ll ind)
{
    // cout << "In comp, AS1: " << s1 << ", J1S2: " << s2 << ", ind: " << ind << endl;
    for (ll i = s1.length() - 1; i >= 0; i--)
    {
        if (i == ind && s1[i] != s2[i])
        {
            // cout << "in return 1 i: " << i << endl;
            return false;
        }

        if (s1[i] == '1' && s2[i] == '0')
        {
            // cout << "in return 2 i: " << i << endl;
            return false;
        }
    }
    // cout << "return true, A S: " << s1 << ", J s: " << s2 << endl;
    return true;
}

bool check2(ll n)
{
    bool ans = (n > 0) && ((n & (n - 1)) == 0);
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<string> v(n);
        vi integers;

        set<ll> ss;

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        ll flag = 0;
        // for(auto i:v)
        // {

        // }
        for (ll i = 0; i < n; i++)
        {
            ll temp = binToDec(v[i]);
            // cout << "SS: " << v[i] << ", int: ";
            if (check2(temp))
            {
                integers.pb(temp);
                ss.insert(temp);
            }
            // cout << integers[i] << endl;
        }

        if (ss.size() == k)
        {
            yes;
            continue;
        }
        else
        {
            no;
            continue;
        }

        ll flag2 = 0;
        sort(integers.begin(), integers.end());
        ll curr = 1;
        ll max = pow(2, k - 1);
        ll index = 0;
        while (true)
        {
            if (curr == max * 2)
            {
                curr /= 2;
                break;
            }
            if (index >= integers.size())
                break;
            if (integers[index] == curr)
            {
                while (index < integers.size() && integers[index] == curr)
                {
                    index++;
                }
                curr *= 2;
                ;
            }
            else
            {
                index++;
            }
        }

        if (curr == max)
        {
            yes;
        }
        else
        {
            no;
        }

        // ll flag = 0;
        // ll flag2 = 0;
        // ll flagi = 0;
        // for (ll j = 1; j < (pow(2, k)); j++) // for each j
        // {
        //     // cout << "in j for\n";
        //     string j1 = decToBin(j);
        //     while (j1.length() < k)
        //     {
        //         j1 = "0" + j1;
        //         // cout << "in + while\n";
        //     }
        //     ll val = 0;
        //     // cout << "j1: " << j1 << endl;
        //     // bool ans = fun(v, j1, val, 0);
        //     for (ll i = j1.length() - 1; i >= 0; i--) // for index in j
        //     {

        //         // cout << "1" << endl;
        //         char curr = j1[i];
        //         flag2 = 0;
        //         for (ll i2 = 0; i2 < n;) // for find inddex char in array
        //         {
        //             // cout << "In for of i2, i: " << i << endl;
        //             // cout << "2" << endl;
        //             // cout << "j1: " << j1 << ", v[i2]: " << v[i2] << endl;
        //             if (v[i2][i] == curr)
        //             {
        //                 if (compare(v[i2], j1, i))
        //                 {
        //                     flag2 = 1;
        //                     val = val | integers[i2];
        //                     // cout << "Val updated: " << val << ", j1: " << j1 << endl;
        //                     break;
        //                 }
        //                 else
        //                 {
        //                     i2++;
        //                 }
        //             }
        //             else
        //                 i2++;
        //         }
        //         if (flag2 == 0)
        //         {
        //             flagi = 1;
        //             break;
        //         }
        //     }
        //     // cout << "j: " << j << ", val : " << val << endl;
        //     if (val != j || flagi == 1)
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        // if (flag == 0)
        // {
        //     yes;
        // }
        // else
        // {
        //     no;
        // }
    }
    return 0;
}