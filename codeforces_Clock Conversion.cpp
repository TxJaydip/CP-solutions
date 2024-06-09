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
        string s;
        cin >> s;
        ll hh;
        string mm;
        string am = "AM";
        string pm = "PM";
        hh = stoi(s.substr(0, 2));
        mm = s.substr(3, 2);
        if (hh < 12 && hh != 0)
        {
            cout << s << " " << am << endl;
        }
        else if (hh == 12)
        {
            cout << s << " " << pm << endl;
        }
        else if (hh == 0)
        {
            cout << 12 << ":" << mm << " " << am << endl;
        }
        else
        {
            hh -= 12;
            if (hh < 10)
                cout << "0" << hh;
            else
                cout << hh;
            cout << ":" << mm << " " << pm << endl;
        }
    }

    return 0;
}