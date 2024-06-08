#include "bits/stdc++.h"
using namespace std;

#define ll long long int

pair<bool, ll> binary_s(ll a[], ll low, ll high, ll key)
{
    ll mid = (low + high) / 2;

    if (key < a[low] || key > a[high])
        return {false, -1};

    if (low > high || (low + 1 == high && a[low] != key && a[high] != key))
        return {false, -1};

    if (low == high && a[low] != key)
        return {false, -1};

    if (a[mid] == key)
        return {true, mid};

    if (a[low] == key)
        return {true, low};

    if (a[high] == key)
        return {true, high};

    if (a[mid] > key)
        return binary_s(a, low, mid, key);

    if (a[mid] < key)
        return binary_s(a, mid, high, key);
    return {false, -1};
}

int main()
{
    ll t;
    ll n;
    cout << "Size of array: ";
    cin >> n;
    ll n2 = n;
    ll i = 0;
    ll a[n];
    cout << "Enter array: " << endl;
    while (n2--)
    {
        cin >> a[i++];
    }
    cout << "\nA: ";
    for (ll i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Number of tests: ";
    cin >> t;
    ll k = 1;
    while (t--)
    {
        ll key;
        cout << "Test " << k++ << ", Number to search: ";
        cin >> key;
        pair<bool, ll> ans = binary_s(a, 0, n - 1, key);
        if (ans.first == true)
        {
            cout << "Number is present at position " << ans.second + 1 << "." << endl;
        }
        else
        {
            cout << "Key Not Found" << endl;
        }
    }

    return 0;
}