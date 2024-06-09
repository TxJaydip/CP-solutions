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
        ll n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        vi b(m);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll ai = 0;
        ll bi = 0;
        ll cnta = 0;
        ll cntb = 0;
        ll cnt_common = 0;
        vi ua;
        vi ub;
        vi common;
        while (true)
        {
            if (ai > 0 && a[ai] == a[ai - 1])
            {
                ai++;
                continue;
            }
            if (bi > 0 && b[bi] == b[bi - 1])
            {
                bi++;
                continue;
            }
            if ((ai >= n && bi >= m) || (a[ai] > k && b[bi] > k))
                break;
            if (ai >= n)
            {
                // ub.pb(b[bi]);
                if (b[bi] > k)
                {
                    break;
                }
                bi++;
                cntb++;
                continue;
            }
            if (bi >= m)
            {
                // ua.pb(a[ai]);
                if (a[ai] > k)
                {
                    break;
                }
                ai++;
                cnta++;
                continue;
            }
            if (a[ai] < b[bi])
            {
                // ua.pb(a[ai]);
                if (a[ai] > k)
                {
                    ai = n;
                    continue;
                    ;
                }
                else
                {
                    ai++;
                    cnta++;
                }
            }
            else if (a[ai] > b[bi])
            {
                // ub.pb(b[bi]);
                if (b[bi] > k)
                {
                    bi = m;
                    continue;
                }
                else
                {
                    bi++;
                    cntb++;
                }
            }
            else
            {
                // common.pb(a[ai]);
                if (a[ai] > k)
                {
                    ai = n;
                    bi = n;
                    break;
                }

                ai++;
                bi++;
                cnt_common++;
            }
        }

        ll req = k / 2;
        // cout << "cnta: " << cnta << ", cntb: " << cntb << ", common: " << cnt_common << ", req: " << req << endl;
        // cout << "\t ANS: ";
        if ((cnta >= req && cntb >= req) || cnt_common >= k || ((max(cnta, cntb) >= req) && (min(cnta, cntb) + cnt_common >= req)))
        {
            cout << "YES" << endl;
            continue;
        }
        if ((max(cnta, cntb) >= req) && (min(cnta, cntb) + cnt_common < req))
        {
            cout << "NO" << endl;
            continue;
        }
        ll least_ab = min(cnta, cntb);
        ll other_ab = max(cnta, cntb);
        // cout<<"Min: "<<least_ab<<", Max: "<<other_ab<<endl;
        cnt_common -= (req - least_ab);
        least_ab += req - least_ab;

        other_ab += cnt_common;

        if (least_ab >= req && other_ab >= req)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}