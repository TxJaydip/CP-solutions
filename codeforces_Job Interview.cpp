// NOT DONE YET

#include "bits/stdc++.h"
using namespace std;

#define ll long long int

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int total = n + m + 1;
        vector<int> a(total);
        vector<int> b(total);

        vector<pair<int, int>> vp(total);

        for (int i = 0; i < total; i++)
        {
            cin >> a[i];
            vp[i].first = a[i];
        }
        for (int i = 0; i < total; i++)
        {
            cin >> b[i];
            vp[i].second = b[i];
        }

        sort(vp.begin(), vp.end(), comp);

        vector<ll> pref1(total, 0);
        vector<ll> pref2(total, 0);

        pref1[total - 1] = vp[total - 1].first;
        pref2[0] = vp[0].second;
        for (int i = total - 2; i >= 0; i--)
        {
            pref1[i] = pref1[i + 1] + vp[i].first;
        }
        for (int i = 1; i < total; i++)
        {
            pref2[i] = pref2[i - 1] + vp[i].second;
        }
    }

    return 0;
}