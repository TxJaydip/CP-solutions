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
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == b && c % 2 == 0)
        {
            cout << "Second" << endl;
        }
        else if (a == b && c % 2 == 1)
        {
            cout << "First" << endl;
        }
        else if (a > b)
        {
            cout << "First" << endl;
        }
        else
            cout << "Second" << endl;
    }
    return 0;
}