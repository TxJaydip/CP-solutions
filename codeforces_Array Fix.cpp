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

bool dsorted(int n)
{
    vector<int> v;
    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = v.size() - 1; i > 0; i--)
    {
        if (v[i] > v[i - 1])
        {
            return 0;
        }
    }
    return true;
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
        vi v;
        iv(v, n);
        int i = n - 1;
        bool flag = 0;
        for (; i > 0; i--)
        {
            if (v[i] < v[i - 1])
            {
                flag = 1;
                i--;
                break;
            }
        }
        if (!flag)
        {
            yes;
            continue;
        }

        flag = 0;
        int lastDigit = v[min(n - 1, i + 1)];
        for (; i >= 0; i--)
        {
            if (dsorted(v[i]) && ((v[i] % 10) <= lastDigit))
            {
                lastDigit = int(to_string(v[i]).front() - '0');
            }
            else
            {
                flag = 1;
                no;
                break;
            }
        }
        if (!flag)
        {
            yes;
        }
    }
    return 0;
}