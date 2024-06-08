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
        ll flag = 0;
        ll cnt = 0;
        ll temp;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (flag == 0 && temp != 0)
            {
                flag = 1;
                cnt++;
            }
            if (flag == 1 && temp == 0)
            {
                flag = 0;
            }
        }
        cnt = min(int(cnt), (2));
        cout << cnt << endl;
    }
    return 0;
}