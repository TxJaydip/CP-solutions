#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back

ll digitSum(ll n)
{
    ll ans = 0;
    if (n < 10)
    {
        return n;
    }
    while (n > 0)
    {
        ans += n % 10;
        ans /= 10;
    }
    return ans;
}

int main()
{
    ll t, n, m, temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ans += digitSum(i);
        }
        cout << ans << endl;
    }

    return 0;
}
