#include "bits/stdc++.h"
using namespace std;

#define ll long long int

bool comp(pair<int, int> l, pair<int, int> r)
{
    if (l.second < r.second)
    {
        return true;
    }
    if (l.second == r.second)
    {
        return l.first <= r.first;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vector<int>> v;
        for (int i = 0; i < k; i++)
        {
            vector<int> v1(3);
            cin >> v1[0] >> v1[1] >> v1[2];
            v.push_back(v1);
        }

        map<int, int> mp;
        for (int i = 1; i <= k; i++)
        {
            mp[i] = 0;
        }
        for (int i = 0; i < k; i++)
        {
            mp[v[i][2]]++;
        }
        int mini = 2001;
        int minEle = -1;
        for (auto i : mp)
        {
            if (i.second < mini)
            {
                mini = i.second;
                minEle = i.first;
            }
        }

        vector<int> ans(n, minEle);
        vector<pair<int, int>> lr;
        for (auto i : v)
        {
            lr.push_back({i[1], i[2]});
        }
        sort(lr.begin(), lr.end(), comp);

        for (auto i : lr)
        {
            cout << i.first << " " << i.second << endl;
        }
        cout << "-----------" << endl;
    }

    return 0;
}