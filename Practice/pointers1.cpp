#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
    int x = 10;
    int *p = &x;
    cout << "x: " << x << ", &x: " << &x << ", p: " << p << ", *p: " << *p << ", &p: " << &p << ", *(&p): " << *(&p) << endl;

    return 0;
}