#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    string num;
    ll ans = 0;
    while (t != 0)
    {
        num = to_string(t);
        t -= *max_element(num.begin(), num.end()) - '0';
        ans++;
    }
    printf("%lld", ans);

    return 0;
}