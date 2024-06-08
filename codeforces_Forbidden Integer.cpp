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
        ll n, k, x;
        cin >> n >> k >> x;
        if (k == 1 && x == 1)
        {
            no;
        }
        else if (x == 1 && k == 2)
        {
            if (n % 2 == 0)
            {
                yes;
                cout << n / 2 << endl;
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << 2 << " ";
                }
                cout << endl;
            }
            else
            {
                no;
            }
        }
        else if (x != 1)
        {
            yes;
            cout << n << endl;
            for (ll i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else
        {
            if (x == 1)
            {
                if (n == 1)
                {
                    no;
                }
                else if (n % 2 == 0)
                {
                    yes;
                    cout << n / 2 << endl;
                    for (ll i = 0; i < n / 2; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
                else
                {
                    yes;
                    cout << n / 2 << endl;
                    for (ll i = 0; i < -1 + n / 2; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << 3 << endl;
                }
            }
        }
    }
    return 0;
}