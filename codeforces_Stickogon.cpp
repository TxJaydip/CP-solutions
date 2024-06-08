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
        unordered_map<int, int> m;
        pair<int, int> temp;
        ll temp1;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp1;
            m[temp1]++;
        }
        ll cnt = 0;
        for (auto i : m)
        {
            cnt += i.second / 3;
        }
        cout << cnt << endl;
    }
    return 0;
}