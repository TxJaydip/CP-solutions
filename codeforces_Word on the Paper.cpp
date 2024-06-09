#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        char a[8][8];
        ll flag = 0;
        ll index1, index2;
        for (ll i = 0; i < 8; i++)
        {
            for (ll j = 0; j < 8; j++)
            {
                cin >> a[i][j];
                if (a[i][j] != '.' && flag == 0)
                {
                    flag = 1;
                    index1 = i;
                    index2 = j;
                }
            }
        }
        while (true)
        {

            if (index1 >= 8)
            {
                break;
            }
            //            cout<<index1<<" "<<index2;
            if (a[index1][index2] == '.')
            {
                break;
            }
            //            cout<<"a"<<endl;
            cout << a[index1][index2];
            index1++;
        }
        cout << endl;
    }

    return 0;
}
