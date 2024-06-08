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
        ll n, x;
        cin >> n >> x;
        if (n % x != 0)
        {
            cout << 1 << endl;
            cout << n << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << n - 1 << " " << 1 << endl;
        }
    }
    return 0;
}