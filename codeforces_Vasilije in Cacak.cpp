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
        ll n, k, x;
        cin >> n >> k >> x;
        ll min;
        ll max;

        min = (k * (k + 1) / 2);
        max = (k * ((2 * n) - k + 1)) / 2;
        cout << "Max: " << max << endl;
        if (x <= max && x >= min)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}