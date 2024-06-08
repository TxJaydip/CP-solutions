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
        ll n, c, d;
        cin >> n >> c >> d;
        vi v(n * n);
        for (ll i = 0; i < n * n; i++)
        {
            cin >> v[i];
        }

        vector<bool> checked(n * n);
        // for (auto i : checked)
        // {
        //     cout << "i: " << i << endl;
        // }
        sort(v.begin(), v.end());
        ll st = v[0];
        ll i = 0;
        ll j = 0;
        ll cnt = 0;
        ll flag = 0;
        while (true)
        {
            cnt = 0;
            j = 0;
            ll curr = st;
            flag = 0;
            // cout << "St: " << st << ", Curr: " << curr << ", i: " << i << endl;
            while (true)
            {
                if (j == n * n)
                {
                    flag = 1;
                    break;
                }
                if (checked[j] == 0 && v[j] == curr)
                {
                    curr = curr + d;
                    checked[j] = 1;
                    cnt++;
                }
                if (cnt == n)
                    break;
                j++;
            }
            // if (flag == 1)
            //     break;
            st = st + c;
            i++;
            if (i == n)
                break;
        }
        ll flag2 = 0;
        for (auto ind : checked)
        {
            if (ind == 0)
            {
                flag2 = 1;
                break;
            }
        }
        // cout << "Checked: ";
        // for (auto c : checked)
        //     cout << c << " ";
        // cout << endl;
        if (flag2)
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