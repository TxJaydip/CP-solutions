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
        vi v(n);
        vi pos(n);
        ll min = INT_MAX;
        ll flag = 0;
        ll ans = -1;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            pos[i] = abs(v[i] - (i + 1));
            if (pos[i] == 0)
                pos[i] = n;
            else
            {
                flag = 1;
                if (ans == -1)
                {
                    ans = pos[i];
                }
                else
                    ans = __gcd(int(ans), pos[i]);
            }

            if (pos[i] < min)
                min = pos[i];
        }
        // if (min == n)
        //     min = n - 1;
        cout << ans << endl;
    }
    return 0;
}

/*                            ANS

                               |
                               |
                               |

1 11 6 4 8 3 7 5 9 10 2
1 2  3 4 5 6 7 8 9 10 11
0 9  3 0 3 3 0 3 0 0  9   ----> 3
*/
/*
3 10 5 2 9 6 7 8 1 4
1 2  3 4 5 6 7 8 9 10
2 8  2 2 4 0 0 0 8 6     -----> 2
*/
/*
1 6 7 4 9 2 3 8 5
1 2 3 4 5 6 7 8 9
0 4 4 0 4 4 4 0 4        ------->4
*/
/*
1 5 3 4 2 6
1 2 3 4 5 6
0 3 0 0 3 3              ------>3
*/
/*
4 2 6 7 5 3 1
1 2 3 4 5 6 7
3 0 3 3 0 3 6              ------>3
*/
/*
3 4 1 2
1 2 3 4
2 2 2 2                    ------->2
*/