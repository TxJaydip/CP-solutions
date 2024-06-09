#include "bits/stdc++.h"
#include "algorithm"
using namespace std;

#define ll int

bool comp(const vector<int> &v1, const vector<int> &v2)
{
    return (v1[0] > v2[0]);
}

bool comp2(const vector<int> &v1, const vector<int> &v2)
{
    return (v1[1] < v2[1]);
}

int main()
{
    ll t;
    ll t1 = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(3));

        for (ll i = 0; i < n; i++)
        {
            a[i][1] = i + 1;
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i][0];
        }

        sort(a.begin(), a.end(), comp);

        for (ll i = 0; i < n; i++)
        {
            a[i][2] = i + 1;
        }

        sort(a.begin(), a.end(), comp2);

        for (ll i = 0; i < n; i++)
        {
            cout << a[i][2] << " ";
        }
        cout << endl;
    }

    return 0;
}