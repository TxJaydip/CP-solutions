#include "bits/stdc++.h"
using namespace std;

#define ll long long int

bool isprime(ll n)
{
    if (n == 1)
        return true;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ll t;
    ll t1 = 1;
    cin >> t;
    while (t--)
    {
        ll l, r, num;
        cin >> l >> r;
        if ((l == r) && isprime(l))
            //			cout<<"\tAns("<<t1++<<"): "<<-1<<endl;
            cout << -1 << endl;
        else if (((l == 1) && (r == 2 || r == 3)) || (l == 2 && r == 3))
            //			cout<<"\tAns("<<t1++<<"): "<<-1<<endl;
            cout << -1 << endl;
        else
        {
            for (ll i = l;; i++)
            {
                if (!isprime(i))
                {
                    num = i;
                    break;
                }
            }
            for (ll i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    //					cout<<"\tAns("<<t1++<<"): "<<i<<" "<<num-i<<endl;
                    cout << i << " " << num - i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}