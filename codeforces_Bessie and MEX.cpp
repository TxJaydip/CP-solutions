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
        vector<int> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll mex = n;
        ll curr;
        ll temp;
        vi ans(n);
        for (ll i = n - 1; i >= 0; i--)
        {
            curr = v[i];
            temp = mex - v[i];
            ans[i] = temp;
            if (temp < mex)
                mex = temp;
        }
        // cout << "\tAns: ";
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}