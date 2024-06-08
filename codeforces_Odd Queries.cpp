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
        ll n, q;
        cin >> n >> q;
        vi v;
        ll sum = 0;
        ll temp = 0;
        vi prefix;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            temp %= 2;
            v.pb(temp);
            sum += temp;
            sum %= 2;
            if (!i)
                prefix.pb(temp);
            else
                prefix.pb(prefix[i - 1] + temp);
        }

        // cout << "Sum : " << sum << endl;
        // cout << "Array: ";
        // for (auto i : v)
        //     cout << i << " ";
        // cout << endl;
        // cout << "Prefixes: ";
        // for (auto i : prefix)
        //     cout << i << " ";
        // cout << endl;
        // cout << "----------------------------\n";
        ll l, r, k;
        for (ll i = 0; i < q; i++)
        {
            cin >> l >> r >> k;
            l--;
            r--;
            ll cnt = 0;
            ll rm;
            ll add;
            if (v[l] == 0)
            {
                rm = prefix[r] - prefix[l];
            }
            else
            {
                rm = prefix[r] - prefix[l] + 1;
            }
            rm %= 2;
            // cout << "K: " << k << endl;
            add = ((r - l + 1) % 2) * (k % 2);
            // cout << "L: " << l << ", R: " << r << endl;
            // cout << "Rm: " << rm << ", Add: " << add << endl;
            if (sum % 2 == 0) // sum even
            {
                if (rm % 2 == 0)
                {
                    if (add % 2 == 0)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
                else
                {
                    if (add % 2 == 0)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
            else // sum odd
            {
                if (rm % 2 == 0)
                {
                    if (add % 2 == 0)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    if (add % 2 == 0)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
            }
        }
    }
    return 0;
}