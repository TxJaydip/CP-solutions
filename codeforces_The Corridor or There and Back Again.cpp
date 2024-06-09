#include "bits/stdc++.h"
using namespace std;

#define ll long long int
//
// bool comp(  )
//{
//
//}

ll count(ll n)
{
    return (floor((n - 1) / 2));
}

int main()
{
    ll t;
    ll t1 = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ds[n][2];
        for (ll i = 0; i < n; i++)
        {
            cin >> ds[i][0] >> ds[i][1];
        }
        //		sort(ds, ds+n, comp);
        ll flag = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            flag = 0;
            for (ll j = i; j < n; j++)
            {
                if (ds[i][0] > ds[j][0])
                {
                    swap(ds[i][0], ds[j][0]);
                    swap(ds[i][1], ds[j][1]);
                    flag = 1;
                }
            }
        }
        ll cnt = ds[0][0] + count(ds[0][1]);

        ll cnt1;
        for (ll i = 0; i < n; i++)
        {
            cnt1 = ds[i][0] + count(ds[i][1]);
            if (cnt1 < cnt)
            {
                cnt = cnt1;
            }
        }
        //		cout<<"\tAns("<<t1++<<"): "<<cnt<<endl;
        cout << cnt << endl;
    }

    return 0;
}