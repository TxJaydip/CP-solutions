#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

ll find(vi &cnt, ll c)
{
    for (ll i = 0; i < 26; i++)
    {
        if (cnt[i] == c)
        {
            return i;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s;
        cin >> n;
        for (ll i = 0; i < n; i++)
            s += "0";

        vi v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        char ch = 'a';
        vi cnt(26);
        for (ll i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                s[i] = ch;
                ll temp = ch - 'a';
                // cout << "temp: " << temp << endl;
                cnt[temp]++;
                ch++;
            }
            else
            {
                ll curr = v[i];

                ll temp = find(cnt, curr);
                // cout << "curr:" << curr << ", temp:" << temp << endl;
                s[i] = 'a' + temp;
                cnt[temp]++;
            }
        }
        cout << s << endl;
    }

    return 0;
}