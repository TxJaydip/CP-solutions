#include "bits/stdc++.h"
using namespace std;

#define ll long double

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll med = (a + b) / 2;
        ll i = (max(a, b) - med) / c;
        cout << ceil(i) << endl;
    }

    return 0;
}