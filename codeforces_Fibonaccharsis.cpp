#include "bits/stdc++.h"
using namespace std;

#define ll long long int

//  CHASER X J

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if ((n == 1 || n == 0) && k == 3)
        {
            cout << 1 << endl;
        }
        else
        {
            ll cnt = 0;
            ll num = n;
            ll len = k;
            ll frm_num = num;
            ll fir_num = frm_num;
            while (true)
            {
                //				cout<<"\n______\nin while start\n";
                ll flag = 0;
                ll j = 2;
                ll nxt_num = num - frm_num;
                fir_num = frm_num;
                //				cout<<"frm_num:"<<frm_num <<", nxt_num:"<<nxt_num<<endl;
                for (ll i = fir_num; flag == 0 && fir_num >= 0 && nxt_num >= 0; i--)
                {
                    //					cout<<"For: "<<i<<", frm_num:"<<fir_num<<", "<<nxt_num<<endl;
                    ll temp = nxt_num;
                    nxt_num = fir_num - nxt_num;
                    fir_num = temp;
                    if (nxt_num < 0)
                    {
                        //						cout<<"\n in if nxt_num<0 break \n";
                        break;
                    }
                    j++;
                    if (j == len)
                    {
                        //						cout<<"\n in break if j==n \n";
                        cnt++;
                        break;
                    }

                } // FOR END
                frm_num--;
                if (frm_num < (num - frm_num))
                {
                    //					cout<<"\n In break while since frm_num=<<"<<frm_num<<", num-frm_num: "<<(num-frm_num)<<"\n";
                    break;
                }

            } // WHILE END

            cout << cnt << endl;
        } // ELSE END
    } // TEST CASES

    return 0;
}
