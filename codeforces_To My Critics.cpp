#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    ll a[3];
    while (t--)
    {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[1] + a[2] >= 10)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}