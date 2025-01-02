#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k > (n * (n - 1)) / 2)
    {
        cout << -1 << endl;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}