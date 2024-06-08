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
        ll n;
        cin >> n;
        string s = to_string(n);
        // if (n < 10)
        // {
        //     cout << n << endl;
        //     continue;
        // }
        // if (n >= 10 && n < 20)
        // {
        //     cout << 10 << endl;
        //     continue;
        // }
        // ll num = pow(10, s.length() - 1);
        // ll ans = n / num;
        // ans = ;
        cout << int(n / (pow(10, s.length() - 1))) + ((9 * (s.length() - 1))) << endl;
    }
    return 0;
}