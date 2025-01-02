#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define alice cout << "ALICE\n"
#define bob cout << "BOB\n"
#define endl "\n";
ll MOD = (7 + (1e9));

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

void iv(vi &v, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.pb(temp);
    }
}

void ov(vi &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void all(vi &v)
{
    sort(v.begin(), v.end());
    return;
}

ll ones_count(int c[], int st, int ed)
{
    ll ans = 0;
    for (int i = st; i < ed; i++)
    {
        if (c[i] == 1)
        {
            ans++;
        }
    }
    return ans;
}

int min_index(int f, int ed1, int c[], int st, int ed, map<int, int> &mp)
{
    int mini = INT_MAX;
    int ans = 1;
    ll st1 = st;
    if (st == f)
    {
        st1++;
    }
    ll ans1 = -1;
    for (int i = st1; i < ed; i++)
    {
        if (c[i] == 1)
        {
            // cout << "ret 1 " << endl;
            // cout << "min_ind , 1 ret: " << i << endl;

            ans1 = i;
            break;
            // return i;
        }
    }
    ll ans2 = -1;
    for (int i = st; i < ed; i++)
    {
        // cout << "mp" << i << ": " << mp[i] << ", mp" << st << ": " << mp[st] << endl;
        if ((c[i] && c[i] <= (mp[i] - mp[st])) || (i != f && c[i] == 1))
        {
            // cout << "min_ind check ret: " << i << endl;
            ;
            // cout << "ret frm if" << endl;
            ans2 = i;
            return i;
        }
    }
    if (ans1 != -1 && ans2 != -1)
    {
        if (ones_count(c, st1, ed) > c[ans2])
        {
            return ans2;
        }
        else
        {
            return ans1;
        }
    }
    if (ans1 == -1 && ans2 == -1)
    {
        // cout << "min_ind end ret: " << ed1 << endl;
        return ed1;
    }
    if (ans1 == -1)
    {
        return ans2;
    }
    return ans1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // cout << "STARTED" << endl;
    while (t--)
    {
        // cout << "t: " << t << endl;
        int n;
        cin >> n;
        vi v;
        iv(v, n);
        int count[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            count[i] = 0;
        }
        for (auto i : v)
        {
            count[i]++;
        }

        all(v);
        // ov(v, n);
        // for (int i = 1; i <= n; i++)
        // {
        //     if (count[i])
        //     {
        //         cout << i << ": " << count[i] << endl;
        //     }
        // }
        ll count_sum = 0;
        vi counts;
        for (int i = 1; i <= n; i++)
        {
            counts.pb(count[i]);
            if (count[i])
            {
                count_sum++;
            }
        }
        all(counts);
        map<int, int> mp;
        int ii = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (count[i])
            {
                mp[i] = ii;
                ii++;
            }
        }
        // cout << "mp: " << endl;
        // for (auto i : mp)
        // {
        //     cout << i.first << ": " << i.second << endl;
        // }
        char flag = 'A';
        int al = 0;
        while (!count[al])
        {
            al++;
        }
        ll f = al;
        ll ed1 = n;
        while (!count[ed1])
        {
            ed1--;
        }
        // cout << "al:" << al << endl;
        int bb = 0, ans = 0;
        ll br_flag = 0;
        ll min_ind = min_index(f, ed1, count, al, n + 1, mp);
        while (true)
        {
            if (flag == 'A')
            {
                int i;
                for (i = al; i <= n; i++)
                {
                    if (count[i])
                    {
                        // cout << "ans+(ALICE): " << i << endl;
                        count[i] = max(0, count[i] - 1);
                        // if (count[i] <= 0)
                        // {
                        //     mp.erase(i);
                        // }
                        ans++;
                        al = i + 1;
                        break;
                    }
                }
                if (al > n || i > n)
                {
                    br_flag = 1;
                    break;
                }

                flag = 'B';
            }
            else
            {

                if (count[min_ind])
                {
                    // cout << "min_index(BOB)  : " << min_ind << endl;
                    count[min_ind] = max(0, count[min_ind] - 1);
                }
                else
                {
                    mp.erase(min_ind);
                    min_ind = min_index(f, ed1, count, al, n + 1, mp);
                    // cout << "min_index: " << min_ind << endl;
                    count[min_ind] = max(0, count[min_ind] - 1);
                }
                flag = 'A';
            }
        }
        cout << ans << endl;
        // cout << "------------------------" << endl;
    }
    return 0;
}
