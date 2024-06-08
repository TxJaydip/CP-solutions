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

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

bool comp(const pair<int, int> &a, const pair<int, int> &tmp)
{
    return (
        a.first <= tmp.first);
}

vpi powers;

int main()
{
    ll current = 01;
    pair<int, int> tmp;

    for (ll i = 0; current < (1 + 2 * 10e5); i++)
    {
        tmp.first = current;
        tmp.second = i;
        powers.pb(tmp);
        current = (1 << (i + 1));
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi v;
        iv(v, n);
        sort(v.begin(), v.end());
        ll cnt = 1;
        ll max_cnt = 1;
        ll i = 0;
        while (true)
        {
            while (i < n - 1 && v[i] == v[i + 1])
            {
                i++;
                cnt++;
            }
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
            }
            if (i >= n)
            {
                if (cnt > max_cnt)
                {
                    max_cnt = cnt;
                }
                break;
            }
            if (cnt == 1)
            {
                i++;
            }
            cnt = 1;
        }
        // ll req = n;
        // long double to_find = (long double)req / (long double)max_cnt;
        // pair<int, int> to_find_pair = make_pair(ceil(to_find), 0);
        // pair<int, int> ans = *upper_bound(powers.begin(), powers.end(), to_find_pair, comp);
        // cout << ans.second << endl;

        ll ans = 0;
        while (max_cnt < n)
        {
            int d = min(n - max_cnt, max_cnt);
            ans += 1 + d;
            max_cnt += d;
        }
        cout << ans << endl;
    }
    return 0;
}