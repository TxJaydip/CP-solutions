#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        // cout << "\tAns: ";
        string s = to_string(n);
        while (s.back() == '0')
        {
            s.pop_back();
        }

        ll num = stoi(s);

        vector<int> ones;
        ones.pb(11);
        ones.pb(111);
        ones.pb(101);
        ones.pb(1001);
        ones.pb(1011);
        ones.pb(1101);
        ones.pb(1111);
        ones.pb(11111);
        ones.pb(10001);
        ones.pb(11001);
        ones.pb(11011);
        ones.pb(11101);
        ones.pb(10101);
        ones.pb(10111);
        ones.pb(10011);

        sort(s.begin(), s.end());
        // cout << s << endl;
        if (s.back() == '1' || s.back() == '0')
        {
            cout << "YES" << endl;
        }
        else
        {
            ll temp = num;
            bool flag = false;
            while (temp > 1)
            {
                flag = 0;
                for (auto i : ones)
                {

                    if (temp % i == 0)
                    {
                        temp /= i;
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if (!flag)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}