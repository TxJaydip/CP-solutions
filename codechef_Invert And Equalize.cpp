#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes sout("YES")
#define no sout("NO")
#define alice sout("ALICE")
#define bob sout("BOB")
ll MOD = (7 + (10e9));

int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);

        ll ans1 = INT_MAX;
        ll prev = 0;
        for (ll i = a; i <= b;)
        {
            ll aa;
            aa = i;
            ll ans = aa - a;

            if (ans > ans1)
                break;
            // cout << "\naa: " << aa << ", -> ";
            while (aa * k <= b)
            {
                aa *= k;
                ans++;
                // cout << aa << " -> ";
            }
            ans += b - aa;
            ans1 = min(ans1, ans);
            i++;
            // cout << ", Ans: " << ans;
        }

        printf("\n%lld\n", ans1);
    }
    return 0;
}