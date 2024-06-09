#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n % 3 == 1 || n % 3 == 2)
        {
            cout << "First" << endl;
        }
        else
            cout << "Second" << endl;
    }

    return 0;
}