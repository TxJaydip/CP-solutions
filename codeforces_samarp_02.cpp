#include <bits/stdc++.h>
using namespace std;
//------------------------------------------------------------------------------------------//
#define ll long long int
#define eb emplace_back
#define ppb pop_back
#define vi vector<ll>
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define mod 7 + 1e9
#define mp map<int, int>
#define init                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
//--------------------------------------------------------------------------------------------//
template <typename Container>
void print(const Container &container);
template <typename Key, typename Value>
void print(const map<Key, Value> &m);
template <typename Key, typename Value>
void print(const unordered_map<Key, Value> &um);
template <typename T>
void print(const vector<vector<T>> &v);
template <typename T1, typename T2>
void print(const vector<pair<T1, T2>> &vp);
template <typename T>
set<T> vecToSet(const vector<T> &vec);
template <typename T>
map<T, int> vecToMap(const vector<T> &vec);
template <typename T>
unordered_map<T, int> vecToUMap(const vector<T> &vec);
string decToBin(ll num);
ll binToDec(string str);
void iv(vi &v);
//------------------------------------------------------------------------------------------------//
int bitwiseInverse(int x)
{
    int inverse = 0, mask = 1;
    while (mask <= x)
    {
        if ((x & mask) == 0)
        {
            inverse |= mask;
        }
        mask <<= 1;
    }
    return inverse;
}

vi fun(ll n)
{
    if (n == 1)
        return {1};
    else if (n == 2)
        return {1, 2};
    else if (n == 3)
        return {1, 2, 3};
    else if (n == 4)
        return {1, 2, 3, 4};
    else if (n % 2 == 1)
    {
        vi v = {2, 1};
        for (int i = 3; i <= n; i++)
            v.eb(i);
        return v;
    }
    else
        return {};
}
void samarp()
{
    ll n;
    cin >> n;

    string temp = decToBin(n);
    // cout << temp << endl;

    int maxk = 0;
    if (n % 2 == 0)
        maxk = pow(2, temp.size());
    else
        maxk = n;

    // cout << maxk << endl;

    vi ans;

    if (n % 2 == 0)
    {
        vector<int> v(n, 0);
        v[n - 1] = n;
        v[n - 2] = bitwiseInverse(n);
        // cout << "Inv: " << bitwiseInverse(n) << endl;
        vi v2 = fun(v[n - 2]);
        // print(v2);
        for (int i = v2.size() - 1, j = n - 2; i >= 0; i--, j--)
        {
            v[j] = v2[i];
        }

        bool arr[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = false;
        }
        for (auto i : v)
        {
            arr[i] = true;
        }

        // print(v);

        // map<int, int> s;
        // s[v[n - 1]] = 1;
        // s[v[n - 2]] = 1;
        // int j = 0;

        // for (int i = 0; i < n; i++)
        // {
        //     if (!s[i])
        //     {
        //         v[j] = i;
        //         s[i] = 1;
        //         j++;
        //     }
        // }
        // ans = v;
    }

    else
    {
        ans = fun(n);
    }
    print(ans);
}
//------------------------------------------------------------------------------------------------//
int main()
{
    init;
    ll t;
    cin >> t;
    while (t--)
        samarp();

    return 0;
}
//----------------------------------------------------------------------------------------------//
template <typename Container>
void print(const Container &container)
{
    for (const auto &element : container)
    {
        cout << element << " ";
    }
    cout << endl;
}

template <typename Key, typename Value>
void print(const map<Key, Value> &m)
{
    for (const auto &pair : m)
    {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;
}

template <typename Key, typename Value>
void print(const unordered_map<Key, Value> &um)
{
    for (const auto &pair : um)
    {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;
}

template <typename T>
void print(const vector<vector<T>> &v)
{
    for (const auto &inner_vec : v)
    {
        cout << "[ ";
        for (const auto &element : inner_vec)
        {
            cout << element << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

template <typename T1, typename T2>
void print(const vector<pair<T1, T2>> &vp)
{
    for (const auto &pair : vp)
    {
        cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    cout << endl;
}

template <typename T>
set<T> vecToSet(const vector<T> &vec)
{
    return set<T>(vec.begin(), vec.end());
}

template <typename T>
map<T, int> vecToMap(const vector<T> &vec)
{
    map<T, int> freqMap;
    for (const T &element : vec)
    {
        freqMap[element]++;
    }
    return freqMap;
}

template <typename T>
unordered_map<T, int> vecToUMap(const vector<T> &vec)
{
    unordered_map<T, int> freqMap;
    for (const T &element : vec)
    {
        freqMap[element]++;
    }
    return freqMap;
}

string decToBin(ll num)
{
    string str;
    while (num)
    {
        str.insert(str.begin(), (num & 1) ? '1' : '0');
        num >>= 1;
    }
    return str.empty() ? "0" : str;
}

ll binToDec(string str)
{
    ll dec_num = 0;
    for (char c : str)
    {
        dec_num = (dec_num << 1) + (c - '0');
    }
    return dec_num;
}

void iv(vi &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
}
//------------------------------------------------------------------------------------------------//