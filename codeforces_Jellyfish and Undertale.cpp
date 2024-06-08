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
        cin >> a >> b >> n;
        ll temp = 0;
        ll sum = b;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            sum += min(a, temp);
            cnt += temp >= a;
        }
        cout << sum - cnt << endl;
    }
    return 0;
}