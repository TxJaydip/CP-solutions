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

bool check(vector<vector<int>> &v, int m, int n, int r, int c)
{
    bool ans = 0;
    int val = v[r][c];
    if (r + 1 < n && v[r + 1][c] >= val)
    {
        return 0;
    }
    if (c + 1 < m && v[r][c + 1] >= val)
    {
        return 0;
    }
    if (c - 1 >= 0 && v[r][c - 1] >= val)
    {
        return 0;
    }
    if (r - 1 >= 0 && v[r - 1][c] >= val)
    {
        return 0;
    }
    return 1;
}

int value(vector<vector<int>> &v, int m, int n, int r, int c)
{
    int ans = 0;
    if (r + 1 < n)
    {
        ans = max(ans, v[r + 1][c]);
    }
    if (c + 1 < m)
    {
        ans = max(ans, v[r][c + 1]);
    }
    if (c - 1 >= 0)
    {
        ans = max(ans, v[r][c - 1]);
    }
    if (r - 1 >= 0)
    {
        ans = max(ans, v[r - 1][c]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check(mat, m, n, i, j))
                {
                    mat[i][j] = value(mat, m, n, i, j);
                }
            }
        }

        for (auto i : mat)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    return 0;
}