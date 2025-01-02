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

int numLength(ll n)
{
    int ans = 0;
    while (n > 0)
    {
        // cout << 3 << endl;
        n /= 10;
        ans++;
    }
    return ans;
}

bool isLarge(ll n)
{
    while (n > 0)
    {
        // cout << 2 << endl;
        if (n % 10 < 5)
        {
            return 0;
        }
        n /= 10;
    }
    return true;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        string s = to_string(n);
        if (s.front() != '1' || s.back() == '9')
        {
            no;
            continue;
        }

        int i = 0;
        int flag = 0;
        int temp = n % 10;
        while (n > 0)
        {
            if (temp == 9)
            {
                no;
                flag = 1;
                break;
            }
            // if (i != 0 && temp == 0)
            // {
            //     cout << 1;
            //     no;
            //     flag = 1;
            //     break;
            // }
            n /= 10;
            temp = n % 10;
            if (temp == 0)
                temp = 10;
            temp--;
            i++;
        }
        if (flag == 0)
        {
            yes;
        }

        // if (n < 10 && n >= 5)
        // {
        //     yes;
        //     continue;
        // }
        // if (n < 5)
        // {
        //     no;
        //     continue;
        // }
        // string s = to_string(n);
        // int nlength = s.length();
        // if (s.back() == '9')
        // {
        //     no;
        //     continue;
        // }
        // // if(n>=10)
        // string s1 = "";
        // string s2;
        // for (int i = 0; i < nlength - 1; i++)
        // {
        //     s1 += "1";
        // }
        // s1 += "0";
        // s2 = "1";
        // for (int i = 0; i < nlength - 2; i++)
        // {
        //     s2 += "9";
        // }
        // s2 += "8";
        // ll f1 = stoll(s1);
        // ll f2 = stoll(s2);
        // if (
        //     n >= f1 &&
        //     n <= f2)
        // {
        //     yes;
        // }
        // else
        // {
        //     no;
        // }

        // cout << "n: " << n << endl;
        // ll half = n / 2;
        // ll shalf = half;
        // if (n % 2 == 1)
        // {
        //     shalf++;
        // }

        // int flag = 0;
        // // cout << "before while" << endl;
        // while (true)
        // {
        //     // cout << "1 - - -- - - - --  -" << endl;
        //     if (
        //         numLength(half) != numLength(shalf))
        //     {
        //         flag = 2;
        //         break;
        //     }
        //     if (
        //         isLarge(half) &&
        //         isLarge(shalf))
        //     {
        //         yes;
        //         flag = 1;
        //         break;
        //     }

        //     half--;
        //     shalf++;
        // }
        // if (flag == 2)
        // {
        //     no;
        // }
    }
    return 0;
}