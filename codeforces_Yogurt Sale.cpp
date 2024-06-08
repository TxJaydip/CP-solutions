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
        ll n, a, b;
        cin >> n >> a >> b;
        if (a > (float(b) / 2))
        {
            if (n % 2 == 0)
            {
                cout << b * (n / 2) << endl;
            }
            else
            {
                cout << int(b * (n / 2)) + a << endl;
            }
        }
        else
        {
            cout << n * a << endl;
        }
    }
    return 0;
}