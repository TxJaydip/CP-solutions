#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define endl "\n";
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define alice cout << "ALICE" << endl
#define bob cout << "BOB" << endl
#define init                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
ll MOD = (7 + (1e9));

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
ll modex1(ll a, ll b);
ll mod(ll a, ll b);
// -----------------------------------------------------------------------------------

pair<int, int> findIndices(vi v, int n)
{
    int minSum = INT_MAX;
    int currSum = 0;
    int tempStart = 0;
    int skipStart = -1;
    int skipEnd = -1;

    for (int i = 0; i < n; i++)
    {
        currSum += v[i];

        if (currSum < minSum)
        {
            minSum = currSum;
            skipStart = tempStart;
            skipEnd = i;
        }
        if (currSum > 0)
        {
            currSum = 0;
            tempStart = i + 1;
        }
    }

    return {skipStart, skipEnd};
}

void solve()
{

    int n;
    cin >> n;
    vi v(n);
    iv(v);

    int x = 0;
    vi ratingChange;
    vi incOrDec;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > x)
        {
            x++;
            // continue;
        }
        else if (v[i] < x)
        {
            x--;
            // incOrDec.pb(-1);
            // continue;
        }

        if (v[i] > maxi)
        {
            incOrDec.pb(1);
        }
        else if (v[i] < maxi)
        {
            incOrDec.pb(-1);
        }
        else
        {
            incOrDec.pb(0);
        }
        maxi = max(maxi, x);
        ratingChange.pb(x);
    }
    int st;
    int ed;
    pair<int, int> stEd = findIndices(incOrDec, n);
    st = stEd.first;
    ed = stEd.second;
    cout << "St: " << st << ", ed: " << ed << endl;

    print(v);
    print(ratingChange);
    print(incOrDec);
    // cout << "-----------------" << endl;

    int ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= st && i <= ed)
        {
            continue;
        }
        if (v[i] > ans2)
        {
            ans2++;
        }
        else if (v[i] < ans2)
        {
            ans2--;
        }
    }
    cout << min(n - 1, max(maxi, ans2)) << endl;

    return;
    // ll x = 0;

    // // vi impact;
    // vi ratingChange;
    // for (int i = 0; i < n; i++)
    // {
    //     if (v[i] > x)
    //     {
    //         x++;
    //         ratingChange.pb(1);
    //         continue;
    //     }
    //     else if (v[i] < x)
    //     {
    //         x--;
    //         ratingChange.pb(-1);
    //         continue;
    //     }

    //     ratingChange.pb(0);
    // }
    // // print(v);
    // // print(impact);

    // // modified Kadane's algo from gfg
    // int minSum = n + 1;
    // int current = 0;
    // for (auto i : ratingChange)
    // {
    //     current += i;
    //     minSum = min(minSum, current);
    //     // cout << "Curr: " << current << ", minSum: " << minSum << endl;
    //     if (current > 0)
    //     {
    //         // cout << "in if" << endl;
    //         current = 0;
    //     }
    // }

    // ll ans = x - minSum;

    // cout << ans << endl;

    // return;

    // ll n;
    // cin >> n;
    // string s, r;
    // cin >> s >> r;

    // ll oneS = count(all(s), '1');
    // ll zeroS = count(all(s), '0');
    // ll oneR = count(all(r), '1');
    // ll zeroR = count(all(r), '0');

    // if (oneS == n || zeroS == n)
    // {
    //     no;
    //     return;
    // }

    // ll maxi;
    // ll flag = 0;

    // sort(all(s));
    // // sort(allr(r));

    // int left = 0;
    // int right = n - 1;
    // while (left < n && s[left] == '0')
    // {
    //     left++;
    // }

    // while (right >= 0 && s[right] == '1')
    // {
    //     right--;
    // }

    // left--;
    // right++;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (r[i] == '0')
    //     {
    //         if (oneS == 0 || zeroS == 0)
    //         {
    //             no;
    //             return;
    //         }
    //         oneS--;
    //     }
    //     else
    //     {
    //         if (zeroS == 0 || oneS == 0)
    //         {
    //             no;
    //             return;
    //         }
    //         zeroS--;
    //     }
    // }

    // yes;
    // return;

    // print(s);
    // print(r);
    // cout << "------------\n";

    // if (oneR > zeroR)
    // {
    //     int i = 0;
    //     while (r[i] == '1')
    //     {
    //         i++;
    //     }
    //     if (i == maxi)
    //     {
    //         no;
    //         return;
    //     }
    // }
    // else
    // {
    //     int i = 0;
    //     while (r[i] == '0')
    //     {
    //         i++;
    //     }
    //     if (i == maxi)
    //     {
    //         no;
    //         return;
    //     }
    // }

    // if (oneR > oneS || zeroR > zeroS)
    // {
    //     no;
    //     return;
    // }
    // yes;
    // return;

    // ll l, r, k;
    // cin >> l >> r >> k;

    // ll div;
    // if (r % k == 0)
    // {
    //     cout << max(0ll, 1 + (r / k) - l) << endl;
    //     ;
    //     return;
    // }
    // cout << max(0ll, 1 + (r / k) - l) << endl;
}
// -----------------------------------------------------------------------------------
int main()
{
    init;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//
//
//
//
//
//
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
    for (const auto &[key, value] : m)
    {
        cout << "{" << key << ": " << value << "} ";
    }
    cout << endl;
}

template <typename Key, typename Value>
void print(const unordered_map<Key, Value> &um)
{
    for (const auto &[key, value] : um)
    {
        cout << "{" << key << ": " << value << "} ";
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
    for (const auto &[first, second] : vp)
    {
        cout << "{" << first << ", " << second << "} ";
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

ll modex1(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    a %= MOD;
    ll temp = modex1(a, b / 2);
    temp *= temp;
    temp %= MOD;
    if (b % 2)
    {
        temp *= a;
        temp %= MOD;
    }
    return temp;
}

ll mod(ll a, ll b)
{
    return ((a % MOD) * modex1(b, MOD - 2)) % MOD;
}

/*
%%%%%%%%%%%%%%%%%%%%%@%@%%%%%%%%%%%%%@%%@@@%%%%%%%%%%%%@%@@%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@%@@@%%@@
%%%%%%%%%%%%%%%%%%%%%@@@%%%%%%%%%%%%%%@@%@%@@%%%%%%%%%%%@%%%%%%%%%%%%%%%%%%@%%@@@@@@@@@@@@%@%@@@%%@@
%%%%%%%%%%%%%%%%%%%%%%@%@%%%%%%%%%%%%%%@%@%%%%@%%%%%%%%%%@%%@%%%%%%%%%%%%#%%%%@@@@@@@@@@@@%@%@@@@%%@
%%%%%%%%%%%%%%%%%%%%%%@@@@%%%%%%%%%%%%%%@@%%%%%%%%%%%%%%%%%%%@%%%%%%%%%%%#%%%%@@@@@@@@@@@@%@%%@@@%%@
%%%%%%%%%%%%%%%%%%%%%%%@@@%%%%%%%%%%%%%%%@%@%%%@%%%%%%%%%%%%%%%%%%%%%%%%%#%%%%@@@@@%@@@@@@%@%%@@@%%@
%%%%%%%%%%%%%%%%%%%%%%%%@%@%%%%%%%%%%%%%%%@@%%%%@%%%%%%%%%%%%%%@%%%%%%%%#%%%%@@@@@%%@@@@@%%@@%@@@%%%
%%%%%%%%%%%%%%%%%%%%%%%%%@%@%%%%%%%%%%%%%%@@%%%%@%%%%%%%%%%%%%%%@%%%%%%%#%%%%@@@@%%%@%@@@%%@@%%@@%%%
%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@%%%%%%%%%%%%@%%%%%@@%%%%%%%%%%%%%%%%@%%%%%#%##%@@@%%%%@%%@@%%@@%%@@@%%
%%%%%%%%%%%%%%%%%%%%%%%%%%@@@%%%%%%%%%%%%%%@@%%%%@%%%%%%%%%%@%%%%%%@%#%##+=%%@@@%%%@@%%@@%%@@%%@@@%%
%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@%%%%%%%%%%%%%%@%%%%@@@@%%%%%@%%%%%%%%%#%%+===%%@@@%%%@%%%@@%%%@%%%@@%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@%%%%%%%%%%%%@%@%%%%%%%%%%%%%@%%%%%%#+-===+%%@@@%%%@%%%@@%%%@@#%@@%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@%%@%%%%%%%%%%%%%@%%%%%%%%%%%%%%%%%%@%%**+++##%%@@@%%@@%%%@@%%%@@%%@@@%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@%@@%%%%%%%%%%@%%%%%%@%%%%%%%%%%%%#**#*%%*=+%%@@%%%@@%%%@@@%@@@%%%@@%
%%@%%%%%%%%%%%%%%%%%%%%%%%%%@%@@@%%@%%%%%%%%%%@%%%%%@%%%%%%%%%%#**%@%%=---*#%@@%%%@@%%%@@@%@@@%%%@@%
%@%%%%%%%%%%%%%%%%%%%%%%%%%%@%@@@%%@@@@%%%%%%%%@%%%%%@%%%%%@%#%@@%#**-----*%%@@%%%@%%%%%@@%%@@%%%@@@
%@%%%%%%%%%%%%%%%%%%%%%%%%%%%@@%%%@%%@%%%%%%%%%@%%%%%%%%%%@@@@@%*+++*--===*##@@%%@@%%%%%@@%%%@%%%%@@
%@%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@%%@%%@%%%%%%%%%%%%%%%@@@@@@@@@#***%@%+----*##@@%%@@%%%%%@@%%%@%%%%@@
%@%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@%%%%%%%%%%%%%%%@@%%@@@@@@%%#+#%@@%#++-----*#*@@%%@@%%%%%@@%%%@@%%%@@
%@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%%%%@@@@@@@@@@%*+#@%@*+++*+-----*#+@@%%@@%%%%@@@%%%@@%%%%@
%@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%@@@@%%%@@@@@@@@%@%*#%%%*+*%*++++-----*#+@@%%@@%%%#@@@#%%@@@%%%@
%@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%@@%%@@@@@@@@@@%%%%%@%#**+*++%*+*+-----*#+@@%%@@%%%%@@@%*%%%@%%%@
%%@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@%%%%%%##*#####%*++-----*#+@@%%@@%%%%%@%@+%%@@%%%@
%%%@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@%@%@@@@@@%@@@%%%%%@%%%%%#*+*%*@@%%%@%%%%%%%@=##@@%%%@
@%%%@@@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@%%=*@%%****+**+=----@+++*+--+%*%@%%%@%%%#%@%#=##%@@%%@
%%%%%@@@%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@%%%%%%@%%@@@@@@@@@@@%@@%%@@@@%@#%#%#%@%%%@%%%#%@%=-*#*@@%%%
%@%%%@@@@@%%%%%%%%%%%%%%@@@@@@@%%%@@@@@@@@@@@@@@@@@@@@@@@@*===------==-==+@@##@@%%@%%##@%%=-+%*@@%%%
%@@%%%%%@@@@@@@@%%@@@@@@@@@@%%%%%%@@@%#+====*@@@@@@@@@%:*@=---:::-----==+@%#%*@@%%@@%##@%#=-=%+@@%%%
%%@%%%@@%%@@@@@@@@@@@@@@%%%%%%%%#@@+===--=--+@%#@@@@@%#+@+.......:::--=+@%#%%*@@%%@@%#*@%*===#+%@%%%
%%%%%%@@@@@@@@@@@@@@@@%%%%%%%%%@%+===---:::::%#-=*@@#=*%*.........::-=#@%%**#*@@%%%@%##@%+=-=#*%@%%%
%%%%%%%%%@@@@@%%@%%%%%%%%%%%%%@*===---::::...:%::#+*%%@+......:::--=*@%%%+-*#*@@%%%%@#*@%=---#*#@%%@
%%%%%%%%%%%@@@%%%%%%%@%%%%%%%#======---:::.:...-##**#=....::::---=#@%%%%+--+%#@@%%%#@#*@@=---#*#@%%@
%%%%%%%%@@@@%%%%%%%@%%%%%%%%%**###*+===-------::::::::::----===#@%%%%%%%==++%#%@%%%#@##@@----##*@%%@
%%%%%@@@%%%%%%%%%%%%%%%%%%%%%%%%%#%%%%%%%@@%#++++=====++*#%@@@%%%%%%%%%#+*+*#@%@@%%#@#*@%----##+@@%@
%%%%@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#**#%%%%%%%%%@%%%%%%%%%%%%#***=-=%%%%+*+*%%*@@%%*##*@#----*#+@%%#
%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%*+=------=%@@%+++**=------#%%#+*++----+%%%*++*%#*@@%%#+%*@#----##+@%%=
%%%%%%%%%%%%%%%%%%%%%%%%%@%*-------------*%%*+++*=-=----#%%%++*+----+%+%%*++###%@@%#=%*@#----##+@%%-
%%%%%%%%%%%%%%%%%%%%%%%%%=------------=--#%%%+++*=----=#%%%%#+++=---=---#%+*###*@@%#***@#----##+@%*-
%%%%%%%%%%%%%%%%%%%%*-#+----------------*%%%%*+++--------*@%%#++*+------=@%++%#*@@%%+*+@#----#**@@=*
%%%%%%%%%%%%%%%%%%*--------------------===%@%%+++**=-------*%%#++--------+%#**@##@%%+*+@@---=%+#@%=#
%%%%%%%%%%%%%%%%*---------------------------+%%*+++=---------#%**---------+%#+%#*%@%#+*@@---=%=#@#+*
%%%%%%%%%%%%%%*-------------------------------=@#++*----------*%**---------+%#%#%#@@@=#%@===+%=%@+%=
%%%%%%%%%%%@=-------------------::-------------*%#++*----------#%++---------#@*###@@#*##@=-=##=%%*#-
%%%%%%%%%*=-------------::::::::::::------------@%%++*----------%%**---------*%*#%#@@#+#@===%*=@%#+-
%%%%%%#+-------------::::::::::::::::-----------=#%#++*---------+%%+*---------*%*##%@@*#@==+#++@##--
%%%%#=-------------::::::::::::::::::-------------=%%++=---------=%%*----------*%*##@@%##=-+#+#@#+--
%%%=------------:::::::::::::::::::::::-------------*#+++----------%#+=---------*####@@%+==#%=@%%=--
#==-------------:::::::::::::::::::::::--------------=%+*-----------*%*----------**%%%@@*=-##*@%#-=-
--==----------::::::::::::::::::::::::::::------------=%+*-----------=%+---------=%#%#%@*==%+%%%=-*%
---------------:::::::::::::::::::::::::::--------------%++:-----------%=:--------=@@#+@@=*#+@%*#%%%
-------------::::::::::::::::::::::::::::::-------------=%*-------------*----------+%%=%@=%#%@%%%%%%
---------:::::::::::::::::::::::::::::::::::::-----------=%*--------------=:-------=@%=#%=%#@@%%%%@%
---------::::::::::::::::::::::::::::::::::::::-----------+@+:---------------------=#@+#+*%%@@%%%%%%
---------:::::::::::::::::::::::::::::::::::::::-----------+%+---------------------=%%+*+#%@@%%%%%%%
---------:::::::::::::::::::::::::::::::::::::::::---------:=@---------------------=#%%%%%%@@%%%%%%%
---------:::::::::::::::::::::::::::::::::::::::::::-------:--+----------------=+###%%%%%%@@%%%%%%@@
---------:::::::::::::::::::::::::::::::::::::::::::::---------------------=#%###%%#%%%%%%@@%%%%%%@%
----------::::::::::::::::::::::::::::::::::::::::::::------------------*#%###%##%%%%%%%%%@@%%%%%%@%
----------:-::::::::::::::::::::::::::----::::::::::------------------*######%%%%%%%%%%%%%%%%%%%%%@@
----------------::::::::::::::::::::::----:::::----------------------=*###%%%%%%%%%%%%%%%%%%%%%%%%@%
--------------------::::::::::::::::::--------------------------------#%%%%%%%%%%%%%%%%%%%%%%%%%%%@%
-------------------::::::::::::::::::::::::-------------------==-----=####%%%%%%%%%%%%%%%%%%%%%%%@@%
=======++#+--------::::::::::::::::::---------------------:--+-------=%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@
%%%%%%%%%@=-----------::::------------:----------------------:*------+%#%#%%%%%%%%%%%%%%%%%%%%%@@@@@
%%%%%%%@@*------------------------------------:------:-------=+--+---*%%%#%%%%%%%%%%%%%%%%%%%@%@@@@%
%%%%%@@@*------------------------------------------------:-%=-=-=----#%%%%%%%%%%%%%%%%%%%%%@%%%@@@@@
%%@%%%%+-----------:---::---:-----:------------:--------*@=-----==--=%%%%%%%%%%%%%%%%%@%%%%@%%%@@@@@
@%%@@%=---------------:-------------:----------------+#@*-------=---=%%#%%%%%%%%%%%%%%%%%%%%%%%@@@@@
%@@@*--=------=--------:------:-----------------:-=#+-*---------==--+%%#%%%%%%%%%%%%@%%%%%%%%%%@@@@@
%@%=----=-------------:--::::----------:-------*#:..*=----------=--=*%%%%%%%%%%%%%%@%%@@%%%%%%%@@@@%
@*---------------::::----------:::---:--:+#+:::...=+------------===-*%%%%%%%%%%%%%@%%%@%%%%%%%%@@@@@
----------------------------------+*+=-:.......:*+-------------=---=#%%%%%%%%%%%%%%@%%%%%%%%%%%@@@@@
=+*%+---------------::----=++++-::...........+@+---------------=---=#%%%%%%%%%%%@@%%%%%%%%%%%%%@@@@%
#*+-----------:----=+*#=::::::...........:-%%=----------------=---==%%%%%%%%%%%@%%%@%%%%%%%%%%%@@@@@
------------=%#+:.::.::.............-#@@@@=-:----------------=---=-+%%%%%%%%%%@%%%@%%%%%%%%%%%%@@@@@
#**+===--:::................:...:*@@@@%+--------------------==-----*%%%%%%%%@%%%%%%%%%%%%%%%%%%@@@@@
:::::.:..................:-=**#@@@%*=----------------------==-----=#%%%%%%%%%@%%%%%%%%%%%%%%%%%@@@@@
::::::...::.......::-=*@@%@@@@#*---------------------------------==%%%%%%%%%@%%%%%%%%%%%%%%%%%%@@@@@
##%%@@@@@@@@@@@@@@%%@@@@@@*-------------------------------==------+%%%%%%@%%@%%%%%%%%%%%%%%%%%@@@@@@
@@@@@@@@@@@%%%%%%%%@@*=-----------------------------------==---=-=+%%%@%%%@@%%%%%%%%%%%%%%%%%%@@@@@@
%%%%%%%%%%%%%%@%*+---------------------------------------------===*%@%%@%%%@%%%%%%%%%%%%%%%%%%@@@@@@
%%%%%%%%%%#*=-------------------:------------------------=----====%%%%%%%@@@%%%%%%%%%%%%%%%%%%@@@@@@
=====--=-------------------------+#----------------------===-===*@%@%%%@@@@%%%%%%%%%%%%%%%%%%%@@@@@@
------------------------------*%%+--------------------=-======+@%%%%@%%@@@@%%%%%%%%%%%%%%%%%%%@@@@@@
-------------------------=##%###-----------------------==-==+%%%%%%%%%%@@@%%%%%%%%%%%%%%%%%%%%@@@@@@
-------------------=+##%%%%%%#+----------------------==-===#@%@%%%%%%%%@@%%%%%%%%%%%%%%%%%%%%@@@@@@@
-------------=+*%%%%%#%%%%%%*----------------------=-====*@%%%%@%%%%%%%@%%%%%%%%%%%%%%%%%%%%%@@@@@@@
======+*#%%%%%%%%%%%%%%%%*=------------------------=-===@%%%%%%%%%%%%%@@%%%%%%%%%%%%%%%%%%%%%@@@@@@@
%%%%%%%%%%%%#%%%%%%%%*=-------------------------======%@%@%%%%%@+#%%%%@%%%%%%%%%%%%%%%%%%%%%%@@@@@@@
%%%%%%%%%%%%%%%%*+=-------------------:--------==+==%%%%%@%%%%#==%%%%@@%%%%%%%%%%%%%%%%%%%%%%@@@@@@@
%%%%%%%%#**+=--------------------------------=====#@%%%%%%%%%*===%%%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@
==--------------------------------------==-=====#@@%@@%%%%%%====+%%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@
----------------------------------------*==+==*@%@@%@%%%%%*-====+%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@
-------------------------------------===+*=+#@%%@%@@%%%%#====-==+%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@
-------------------------------------+++=+#@%@%%%%@%%%%+=-===-=-*%@@%%%%%%%%%%%%%%%%%%%%%%%@@@%@@@@@
---:-:-------------::-:----------=-==+=*#@%%%%%%%@%%%#==-====-==%%@@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@
--=---:----=----------------=-====-==*@@%%%%%%%%%@%%*-=-==---==%%@@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@
-----------=-------------=--=-====-#@@%%%@%%%%%%@%#=--=-=---=-*%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@
--------------==---=-----==-=+==*%%%%@@%%%%%%%%%@#==-------==+%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@
-=--=-------------=-=-=-=-=-=*%@@@%@@%%%%%%%%%%@%===-------=+%%@@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@
-=---:------===-=-=-==-==+#@@@@@@@@%%%%%%%%%%%%@+=---------+%%%@%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@%
-=--=--==-=--==--=====%@@@@@@@@@@%%%%%%%%%%%*%@*-=--------+%%%@%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@%

 */

/*




    @@@%=*@@@@@++%@@@@@@@*=#%@@@@@@%@%@@@@@@%@@@@%@@@@@@@@@%@@%@%%@@@@%@%@@@@*#@@@@@@@@@@@@%*@@@%%::::-+*+%@@%%@@#%@@@#%@%@@@%@@@@@%++%@@@@@%%%%%%%
    @@@%=%@@@@@+#@@@@@@@%==%@@@@@@@+*%@@@@@@@%@%#=%%@@@@@@@@@@%%%@@@@@%%@@@@#+%@@@@@@@@@@@@+#@@@@#:::::=++*@@@#@%#*@@@@#@*@@@#@@@@%%+=#%@@@@%%%%%%%
    @%@@%@@@@@@#@@@@@@@%%=*@@@@@%@#=+%@@@@@@@@%@*=#@@@@@@@@@%%%@@@@@@@@%@@@@++@@@@%%%@@@@@%+#@%@%+...::=+++%@@+%@#+@@@@*@+@@@%%@@@%%*=#%@@@@%%%%%%%
    @@@@@@@@@@@@@@@@@@@@#=%%%@@@@@*=#@@@@@@@@%%%=+%@@@@@%%%%@@*@@@@@@@%%@@@*++@@@%%#@@%@@@*+%@@%%-::::::+++*@@##@*+%@@@@@+*@@@@@@@%@%=+@@@%@@%%%%%%
    @@@@@@@@@@@@@@@@@@@%%%@@@@@@@@*=%@@@@@@@@@@#=*@@@@@@+%@@@%=%@@@@@%+@@@#++*@@%%##@@@@@%++@@@%%:::::::=+++@@@%@+=*@@@@%++@@@@@@@@@%**%@@%@@%%%%%%
    @@@@@@@@@@@@@@@@@@@@%@%@@@@@@%*+@@@@@@@@@@@*=%@@@@@*+@@%@*+@@@@#@##@@#+++#@@@@+#@%@@%+++@@@@-.::::::-+++#@@@@+-+@@@@*++%@@@@@%@@@%@%@%%%%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@%@@@@@@@%@@@@@@@@@%@%#*@@@@@#+#@@@%+#@@@*%@#@@@++++%@@@%+#@@@@#=+*@@%#::.::::::+++*@@@%=-+@@@@==+#@@@@@@@@%%%%@%%%%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@%@@@@@@%++#@%%%*@@@#*@@%@@=++++@@@@#=%@@@%=++#@@@+.:.::::::=+*+@@@%-:+%@@%:-++@@@@@@@@%%%%@%%%%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@**%@@%@@@@@@*+-%%@@%@@@%+#@@@@*-++++@@@@#*%@%%*-+*%@@%-:::::::.:-++*#@@%-:=%@@%::=+@@@@@%@%%@%@@@%%%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@*+*@@%%@@@@@#+-:%@%@@@@@++%@@@@:-+++*@@@%%%@%%%:=++@@@+.:::::::.::+++*@@#::=%@@=::=+#@@@@@%%%@%@@@%%%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@%+++%%%@@@@@@+=:-%%%%@@@+++@@%@=.=+++#@@%@%@%%%*:++*@@%::::::::::.:++++@@#.:=#@%...-+*@@@@@%%%%%@@@%%%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++=-#%%@@@@@#+::-%%%@@@#++*@%@#::=+++#@@%%%@%%#:-++#@%+::::::::::::+++=@@=::=#@=::::*%@@@@@%%%@@@@@@@%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*++-.*%%@@@@%+=.:-%%%@@%+++*@%@=.:++++%@%%@%%%%-:-+*%%#:.:::::::::::=+==@%:::=%%:=#::++@@@@%%@%%@@@@@@%%%%%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**+-:.=#%@@@@*+:.:-%%@@%:=+*#%%#::-+++*%%%%%%%%*::=++%%=:::::::::::::-+-=@*:.:%@+:.:.:=*@@@@%%%@@@@@@@@%@%@%@#
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%++=::::%%@@@@*-::.-#%%@+:+**%%%-:.-++**%%%%%%%#::-+*#%#::::::::::::::=+-=@*%#-=*.:::::=+%@@@%%%@@@@@@%%%%%@%%*
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*++::::.*%@@@#+::::-#%%#:-+++#%*::.-+**+#%%%%%%-::=++%#:::::::::::::::===%@#+++*::.:.=-=+%@@@@@%@@@@@@%%%%%%@%*
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#++-...::-%@@@*=..::-#%%-:-++-*#+:::-+*+=#%%%%#*:.:++=%=::::::::::.:-..#@*%@*+=:-%@@#...=#%@@@%@@@@@@@%@%@%%@%##
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***+++=-:-#%@@*-:.:.=##*::=++:*#:...=+*+-*%%%#*:.:=+=+*::::::::::.:.-**+%+%+*@@@@@@@@@@--+@@@@@%*@@@@@%@%@@%@%##
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#++::::::::+%%#=--+*%@@@%+=++=.##:::.=+*+.*##%%-:::=+:*::::::::::::.:+*%**#@@@@@@+==#@@@@@*@@@@%**@@@@@%@%@@%@#*#
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*+=:::::::::#%#=:::::-##+*+++*#@@@@@@@@@%+*#%#-.::=+:+-:::::::::::::=+**@@@@@@@@@*===-*@@@@@@@%+*#@@@@@@@@@%%#***
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@#++:::.::::::=#*-::::::*-.::=+*#@@#*+****+:#%%#:::-+:--:::::::::::::::*@@@+.*@@:=@-..:-*@-%@@@%***%@@@@@@@@@@%#*+#
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@**=::::::::::=@#**+**##%*==-==.=*:=+*******##*.:.:=::::::::::::::::.::@@@:..%@@@@@:...-+.*@@@#*#**@@@@@%@%@%###**%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@++:::::.:.::*@@@@@@@@@@@@@@@@@@@@@@@=+**+=:**::::-:::::::::::::::::::#=%@%*@@@@@=:...--.+@@@#####%@@@@@@@@@%####%@
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@++:::::=*@@@@@@#=*#.:%@@@@@@@@@@@#%@@+:=:::+::::::::::::::::::::::::::.#@@@@@@%:=:..:.:*@@@@%####@@@@@@@@%#####%@%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=.:.-%@@@@@*-==**. .:#@@@@@=.:@@*====-=::::::::::::::::::::::::::::...+@%=++=-*+..::.#@##%@%###%@@@@@@@%***+**%%#
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=+==-:@%....%@@@@@@@@@@-...::::.::::::::::::::::::::::::::::::#*=--=#@@++::-:+*##%@%*#@@@@@@@#*+++++%%**
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-::=@@@*===:..:@@@@@@@@@@@@@@@@%....:::::::::::::::::::::::::::::::..:--:::::::::::::-****#%@%%@@@@@@#*++**+##+**
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-.::::*@@=:....#@@@@@@@@@@@@#.......:::::::::::::::::::::::::::::::::::::::::::::::::*##***#@@@@@@@%#******%#***#
    @@@@@@@@@@@@@@@@@@@@%@@@@@@@@@+.:::.::.%#.....@@@*===*-===%@@....:::::::::::::::::::::::::::::::::::::::::::::::::=##*****@@@@@@#*******#**####
    @@@@@@@@@@@@@@@@@@@@**@@@@@@@@%..::::::::=+....*@+====--=-+@#@%-::::::::::::::::::::::::::::::::::::::::::::::::::*#*****#@@@@#****************
    @@@@@@@@@@@@@@@@@@@@*++@@@@@@@@=:::::::::::..::.:=@@@@@#+-:::::::::::::::::::::::::::::::::::::::::::::::::::::::-###***#@@@@#######**+********
    @@@@@@@@@@@@@@@@@@@@**+=@@@@@@@%:::::::::.::::.-:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::#@#***#@@##@%######***********
    @@@@@@@@@@@@@@@@@@@@***+:%@@@@@@=::.:::::::::::::::::::::::::::::::::::::::::::::::::::::::::#::.:::::::::::::::=@@%#**##*##@@######**#########
    @@@@@@@@@@@@@@@@@@@@**+++-@@@@@@@.:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::##-::::::::::::::*@@@########@@########%%#######
    @@@@@@@@@@@@@@@@@@@@#*+**=-@@@@@@*:::::::::::::::::::------------:::::::::::::::::::::::::::::. ###:::::::::::::@@@@%##**%%#%@########****#####
    @@@@@@@@@@@@@@@@@@@@#*****-+@@-@@@-:::::::::::::::::-------------:::::::::::::::::::::::::::::::##:::::::::::::#@@@@%**#%%##%@%#######*#**##***
    @@@@@@@@@@@@@@@@@@@@#*****+-#@+:+@@:::::::::::::::::-------------::::::::::::::::::::::::::::::#::::::::::::::-@@@@%###%%###%@########*******++
    @@@@@@@@@@@@@@@@@@@@#***+***-@%.::%#::::::::::::::::::::----------:::::::::::::::::::::::::::::::::::::::::.:.%@@@@#*#%@%###%%########**####***
    @@@@@@@@@@@@@@@@@@@@%#+*+*****@-.::--:.:.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::%@@@@@%%%%%%###@%###############**
    @@@@@@@@@@@@@@@@@@@@%*#*******@+:::.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::#@@@@@%%%%%%####@####%#############
    @@@@@@@@@@@@@@@@@@@@@*+*#*****%%::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.%@@@@@@%@%%%####%%####%@%##%########
    @@@+@@@@@@@@@@@@@@@@@****##****@+::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.:-@@@@@@@@@@@%%####%#%%##%%%%#%##****##
    @@*+@@@@@@@@@@@@@@@@@**+**+##**@#*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::%@@@@@@@@@@@@%#%%#######%%%%####*******
    @*+*%@@@@@@@@@@@@@@@@*********###**=:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.:.::*@@@@@@@@@@@@@@%%##**####****##*####**##*
    ***+%@@@@@@@@@@@@@@@@#*********#%#***-.:::::::::::::::::::::::::::::::::::::::::::::::.::::::::::.:.+@@@@@@@@@@@@@%%%###*******+**#*#####******
    ***+#@@@@@@@@@@@@@@@@%************##**+-:::::::::::::::::::::::::::::::::::::=####::::::::::::.::.+@@@@@@@@@@@@@@@###****+++**+++********+++***
    ***+*@@@@@@@@@@@@@@@@%***************%#*+-:::::::::::::::::::::::::::::::=####=:::::::::::::.:::-@@@@@@@@@@@@@@@@**#*******+*****+++*****+++***
    *****@@@@@@@@@@@@@@@@@******************%#+-::::::::::::::::::::::::::::::-:::::::::::::::::::-@@@@@@@@@@@@@@@@@%**********###*+++++********##*
    *****%@@@@@@@@@@@@@@@@********************##+:::::::::::::::::::::::::::::::::::::::::::::..-%@@@@@@@@@@@@@@@@@@%#**++****##**+++++*#*+**#***##
    *****#@@@@@@@@@@@@@@@@#*********************###=::::::::::::::::::::::::::::::::::::::::.::%@@@@@@@@@@@@@@@@@@@@@##**+**#***+++++****++*****##%
    *****#@@@@@@@@@@@@@@@@%*************************#*:::::::::::::::::::::::::::::::::::::::%@@@@@@@@@@@@@@@@@@@@@@@@%#**##**+++***+********#%%%%#
    ******@@@@@@@@@@@@@@@@@******************************=::::::::::::::::::::::::::::.::::%@@@@@@@@@@@@@@@@@@@@@@@@@@#*++****+***++********#######
    ******@@@@@@@@@@@@@@@@@#***************************#***#*:.:.:::::::::::::::::::::.:.*@@@@@@@@@@@@@@@@@@@@@@@@@@@##+***###***++*+++*****#######
    ******@@@@@@@@@@@@@@@@@@************************************#-::::::..:::::::::::::+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**#######*****+++**+**#**+*###
    ******@@@@@@@@@@@@@@@@@@***********************************###****=:.::-::.::::::+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@####******#########*###*#*####
    -+****@@@@@@@@@@@@@@@@@@#*********************************#***#***#*=:-==:::.-.=:.:..:%@@@@@@@@@@@@@@@@@@@@@@@@@@####*#####%%%%%%%%#####%######
    ::-***@@@@@@@@@@@@@@@@@@@*******************************##**********-::+@@@@@@:........:..+@@@@@@@@@@@@@@@@@@@@@@%##**####%%%##%%%%###%%#%#####
    ::::=*@@@@@@@@@@@@@@@@@@@#*****************************%#**********=:::@@@@@@%:...........:: .@@@@@@@@@@@@@@@@@@@%##*######**####%%%######%####
    :::::.*@@@@@@@@@@@@@@@@@@%***************************##*****#******-::=@@@@@@#........:..::...=@@@@@@@@@@@@@@@@@@@########**###*##%%%#####%%#**
    ::::::+@@@@@@@@@@@@@@@@@@@**************************%#************=:::@@@@@@@=..::............:@@@@@@@@@@@@@@@@@@@%%%#########*#*#########%%###
    @-::::-@@@@@@@@@@@@@@@@@@@%************************#*************+:::#@@@@@@@::............::::*@@@@@@@@@@@@@@@@@@@%%#########*****#######%%#%%
    @@%-::-@@@@@@@@@@@@@@@@@@@@***#******************##*************+:::=@@@@@@@-:::.::::::::::.:.::@@@@@@@@@@@@@@@@@@%%%%%%######*##***#####%%###%
    @@@@%::@@@@@@@@@@@@@@@@@@@@#*********************%**************-::+@@@@@@@#:::::::::::::::::::.*@@@@@@@@@@@@@@@@@*+%@%%%%%%###***+*##%%%%%##%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@********************#**************-::=@@@@@@@#.::::::::::::::::.:::-@@@@@@@@@@@@@@@@@#:::*@@%%%#*##***###%%#%%##%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@%*****#******#*****##*#***********:::*@@@@@@@@:.::::::::::::::::::::-@@@@@@@@@@@@@@@@@@:..::#%@@#**###*#***###%#%%%
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@**#***************%********#****-:-@@@@@@@@#.:.:::::::::::::::::::::@@@@@@@@@@@@@@@@@@+:::::-@@%@@###*#%##%%%%#%@@
    -@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-=*#*************##*#********+-:#@@@@@@@@=:::::::::::::::::::::::::%@@@@@@@@@@@@@@@@@#::::::.%@@@%%#%%%%%%%%%%%@%
    :::*@@@@@@@@@@@@@@@@@@@@@@@@@@=:::=*****#*******%*#*******=:#@@@@@@@@@:::::::::::::::::::::::::::=@@@@@@@@@@@@@@@@@@-::::::.*%%%%%%%%%@@@@%%%%%
    ::--:=@@@@@@@@@@@@@@@@@@@@@@@@%:::::-=+******#***%******+-@@@@@@@@@@=:::::::::::::::::::::::::::::@@@@@@@@@@@@@@@@@@+::::::::#@@@%%%%%@@@@%%%%%
    --:::-::%@@@@@@@@@@@@@@@@@@@@@@*:--::::::-+****#******%@@@@@@@@@@@-:::::::::::::::::::::::::-:-:::#@@@@@@@@@@@@@@@@@@:::::::::#@@@@@@@@@@%%%%%%
    ------::*@@@@@@@@@@@@@@@@@@@@@@@@@@*-:::::::::-:-+%@@@@@@@@@@@@@-::::::::::::::::::::::::::::::=::+@@@@@@@@@@@@@@@@@@=:::::::::%@@@@@@@@@@@@@@%
    ---------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:-:::::::::::::::::::::::::::-:::-=:-@@@@@@@@@@@@@@@@@@#:::::::::-%@%@@@@@@@@@@@@
    --------:%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=---::::--------------------------::::-=:@@@@@@@@@@@@@@@@@@@-:::::::::*%@@@@@@@@@@@@@
    ---------*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=-:-:-:----------------------------------:--==@@@@@@@@@@@@@@@@@@%:--::::::-@@@@@%@@@@@@@@
    ------=--=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=------:---:-------------------------------------:=:@@@@@@@@@@@@@@@@@@@=:::::::-:+@@@@@@@@@%@@@




*/

/*
      __
     /  l
   .'   :               __.....__..._  ____
  /  /   \          _.-"        "-.  ""    "-.
 (`-: .---:    .--.'          _....J.         "-.
  """y     \,.'    \  __..--""       `+""--.     `.
    :     .'/    .-"""-. _.            `.   "-.    `._.._
    ;  _.'.'  .-j       `.               \     "-.   "-._`.
    :    / .-" :          \  `-.          `-      "-.      \
     ;  /.'    ;          :;               ."        \      `,
     :_:/      ::\        ;:     (        /   .-"   .')      ;
       ;-"      ; "-.    /  ;           .^. .'    .' /    .-"
      /     .-  :    `. '.  : .- / __.-j.'.'   .-"  /.---'
     /  /      `,\.  .'   "":'  /-"   .'       \__.'
    :  :         ,\""       ; .'    .'      .-""
   _J  ;         ; `.      /.'    _/    \.-"
  /  "-:        /"--.b-..-'     .'       ;
 /     /  ""-..'            .--'.-'/  ,  :
:`.   :     / :             `-i" ,',_:  _ \
:  \  '._  :__;             .'.-"; ; ; j `.l
 \  \          "-._         `"  :_/ :_/
  `.;\             "-._
    :_"-._             "-.
      `.  l "-.     )     `.
        ""^--""^-. :        \
                  ";         \
                  :           `._
                  ; /    \ `._   ""---.
                 / /   _      `.--.__.'
                : :   / ;  :".  \
                ; ;  :  :  ;  `. `.
               /  ;  :   ; :    `. `.
              /  /:  ;   :  ;     "-'
             :_.' ;  ;    ; :
                 /  /     :_l
                 `-'
*/