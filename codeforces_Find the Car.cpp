#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll MOD = (7 + (10e9));

string decToBin(ll num)
{
    string str;
    while (num)
    {
        if (num & 1)
            str += '1';
        else
            str += '0';
        num >>= 1;
    }
    return str;
}

ll binToDec(string str)
{
    ll dec_num = 0;
    ll power = 0;
    ll n = str.length();
    for (ll i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            dec_num += (1 << power);
        }
        power++;
    }
    return dec_num;
}

void iv(vi &v, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

int binary_search_find_index(std::vector<int> v, int data)
{
    auto it = std::lower_bound(v.begin(), v.end(), data);
    if (it == v.end() || *it != data)
    {
        return -1;
    }
    else
    {
        std::size_t index = std::distance(v.begin(), it);
        return index;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, q;
        cin >> n >> k >> q;
        vi a;
        vi b;
        iv(a, k);
        iv(b, k);
        ll q1 = q;
        while (q1--)
        {
            ll q_temp;
            cin >> q_temp;
            int flag = 0;
            // for (ll i = 0; i < k; i++)
            // {
            //     if (a[i] == q_temp)
            //     {
            //         cout << b[i] << " ";
            //         flag = 1;
            //         break;
            //     }
            // }
            ll idx1 = binary_search_find_index(a, q_temp);
            if (idx1 != -1)
            {
                cout << b[idx1] << " ";
                continue;
            }
            ll base_pos = 0;
            ll base_time = 0;
            ll idx = 0;
            if (a[0] >= q_temp)
            {
                base_time = 0;
                ll req = q_temp;
                ll slot_time = b[0];
                ll slot_distance = a[0];

                ll ans = base_time + (req * slot_time / slot_distance);
                cout << ans << " ";
                continue;
            }
            else
            {
                auto lower = lower_bound(a.begin(), a.end(), q_temp);
                ll idx2 = (lower - a.begin());
                if (idx2 != 0 && (a[idx2 - 1] <= q_temp && a[idx2] > q_temp))
                {
                    idx2--;
                }
                else if (idx2 != k - 1 && (a[idx2 + 1] <= q_temp && a[idx2 + 2] > q_temp))
                {
                    idx2++;
                }
                // cout << "\nq: " << q_temp << ", idx2: " << idx2 << endl;
                // else if(a[idx2] <= q_temp && a[idx2 + 1] > q_temp)
                // {

                // }
                base_time = b[idx2];
                base_pos = a[idx2];
                idx = idx2;
                // for (ll i = 0; i < k - 1; i++)
                // {
                //     // cout << "in for\n";
                //     if (a[i] <= q_temp && a[i + 1] > q_temp)
                //     {
                //         base_time = b[i];
                //         base_pos = a[i];
                //         idx = i;
                //         break;
                //     }
                // }
            }

            ll req = q_temp - base_pos;
            ll slot_distance = a[idx + 1] - a[idx];
            ll slot_time = b[idx + 1] - b[idx];

            ll ans = base_time + req * slot_time / slot_distance;
            int ans2 = ans;
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}