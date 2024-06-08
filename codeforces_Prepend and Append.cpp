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
        string s;
        cin >> n;
        cin >> s;
        deque<bool> d;
        bool temp;
        for (ll i = 0; i < n; i++)
        {
            temp = stoi(s.substr(i, 1));
            d.push_back(temp);
        }
        while (true)
        {
            if (d.empty() || d.front() == d.back())
            {
                break;
            }
            if (d.front() != d.back())
            {
                d.pop_back();
                d.pop_front();
            }
        }
        cout << d.size() << endl;
    }
    return 0;
}