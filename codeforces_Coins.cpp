#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n == k)
        {
            yes;
            continue;
        }

        if ((n % 2 == 0) || (n % 2 == 1 && k % 2 == 1) || (n % k == 0))
        {
            yes;
            continue;
        }
        else
            no;
    }
    return 0;
}