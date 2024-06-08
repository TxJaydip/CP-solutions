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
        ll n, k;
        cin >> n >> k;
        vi v(n);
        ll sum = 0;
        deque<int> d;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            d.push_back(v[i]);
        }
        if (k >= sum)
        {
            cout << n << endl;
            continue;
        }
        // else
        // {
        //     ll flag = 0;
        //     ll curr_min = 0;
        //     ll attacks = k;
        //     while (true)
        //     {
        //         if (d.empty())
        //         {
        //             break;
        //         }
        //         curr_min = min(d.front(), d.back());
        //         if(d.front() == d.back())
        //         {
        //             curr_min = d.front();
        //             if(flag == 0)
        //             {

        //             }
        //             else
        //             {

        //             }
        //         }
        //         else if(d.front()<d.back())
        //         {
        //             curr_min = d.front();
        //         }
        //         else
        //         {
        //             curr_min = d.back();
        //         }

        //         if (attacks < curr_min)
        //         {
        //             break;
        //         }
        //         if (attacks < 2 * (curr_min))
        //         {
        //             if (d.front() == curr_min)
        //             {
        //                 d.pop_front();
        //             }
        //             else
        //             {
        //                 d.pop_back();
        //             }
        //         }
        //         else
        //         {
        //             if(flag == 0)
        //             {
        //                 if (d.front() == curr_min)
        //                 {
        //                     d.pop_front();
        //                     d.back() -= curr_min;
        //                     attacks -= (2 * curr_min);
        //                 }
        //                 else
        //                 {
        //                     d.pop_back();
        //                     d.front() -= curr_min;
        //                     attacks -= (2 * curr_min);
        //                 }
        //             }
        //             else
        //             {
        //                 if (d.front() == curr_min)
        //                 {
        //                     d.pop_front();
        //                     d.back() -= curr_min;
        //                     attacks -= (2 * curr_min);
        //                 }
        //                 else
        //                 {
        //                     d.pop_back();
        //                     d.front() -= curr_min;
        //                     attacks -= (2 * curr_min);
        //                 }
        //             }

        //         }
        //     }
        //     cout << n - d.size() << endl;
        // }

        // _________________________________________________________________________________________

        int ch = 0;
        ll attacks = k;
        while (!d.empty() && attacks > 0)
        {

            if (ch == 0)
            {
                if (d.front() < d.back() && 2 * d.front() <= attacks)
                {
                    d.back() -= d.front();
                    d.pop_front();
                    attacks -= (2 * d.front());
                    ch = 1;
                }
                else if (d.front() == d.back() && 2 * d.front() <= attacks)
                {
                    d.back() = 1;
                    d.pop_front();
                    ch = 1;
                    attacks -= (2 * d.front());
                }
                else if (d.front() > d.back() && 2 * d.back() <= attacks)
                {
                    d.front() -= d.back();
                    d.pop_back();
                    ch = 0;
                    attacks -= (2 * d.back());
                }
                else
                    break;

                // ch = 1;
            }
            else
            {
                if (d.front() < d.back() && 2 * d.front() <= attacks)
                {
                    d.back() -= d.front();
                    d.pop_front();
                    attacks -= (2 * d.front());
                    ch = 0;
                }
                else if (d.front() == d.back() && 2 * d.front() <= attacks)
                {
                    d.back() = 1;
                    d.pop_front();
                    ch = 0;
                    attacks -= (2 * d.front());
                }
                else if (d.front() > d.back() && 2 * d.back() <= attacks)
                {
                    d.front() -= d.back();
                    d.pop_back();
                    ch = 1;
                    attacks -= (2 * d.back());
                }
                else
                    break;

                // if (d.back() == 1)
                //     d.pop_back();
                // else
                //     d.back()--;
                // ch = 0;
            }
            // attacks--;
        }
        cout << n - d.size() << endl;

        // __________________________________________________________________________________
        // ll ch = 0;
        // sum = 0;
        // ll attacks = k;
        // ll l = 0;
        // ll r = 0;
        // if (d.front() > attacks && d.back() > attacks)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // ll i = 0;
        // while (!d.empty())
        // {
        //     if (l < r)
        //     {
        //         if (l + r + d.front() > attacks)
        //         {
        //             break;
        //         }
        //         else
        //         {
        //             l += d.front();
        //             d.pop_front();
        //         }
        //         i++;
        //     }
        //     else
        //     {
        //         if (l + r + d.back() > attacks)
        //         {
        //             break;
        //         }
        //         else
        //         {
        //             r += d.back();
        //             d.pop_back();
        //         }
        //         i++;
        //     }
        // }
        // cout << n - d.size() << endl;
    }
    return 0;
}