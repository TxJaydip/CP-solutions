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
        double a, b, c, d, x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d;
        x = c;
        y = d;
        x1 = a;
        y1 = b;
        x2 = a + 1;
        y2 = b + 1;
        double cal = ((x - x1) * (y2 - y1)) - ((y - y1) * (x2 - x1));

        if (
            (d >= b) &&
            (cal <= 0))
        {
            ll d1 = d - b;
            ll r = a + d1;
            ll l = r - c;
            cout << d1 + l << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}