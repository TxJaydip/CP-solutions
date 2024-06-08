#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cnt = 0;
        for (auto i : s)
        {
            if (i == '1')
                cnt++;
        }
        if (cnt == 2)
        {
            bool flag = 0;
            for (ll i = 0; i < n - 1; i++)
            {
                if (s[i] == '1' && s[i + 1] == '1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else if (cnt % 2 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}