#include <bits/stdc++.h>
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
        ll n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n <= 2)
        {
            if (n == 1)
            {
                if (v[0] == 0)
                {
                    yes;
                    continue;
                }
                else
                    no;
            }
            else
            {
                if (v[0] == 0 && v[1] == 0)
                {
                    yes;
                    continue;
                }
                else
                    no;
            }
        }
        else
        {
            unordered_map<int, int> m;
            for (auto i : v)
            {
                cout << i << ", ";
                m[i]++;
            }
            cout << "M[1]: " << m[1] << endl;
            if (m[1] % 2 == 0)
                yes;
            else
                no;
        }
    }
    return 0;
}