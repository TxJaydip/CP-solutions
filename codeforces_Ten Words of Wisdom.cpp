#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n][2];
        ll max = -1;
        ll maxIndex = -1;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i][0];
            cin >> a[i][1];
            if (a[i][0] <= 10)
            {
                if (a[i][1] >= max)
                {
                    max = a[i][1];
                    maxIndex = i;
                }
            }
        }
        cout << maxIndex + 1 << endl;
    }

    return 0;
}
