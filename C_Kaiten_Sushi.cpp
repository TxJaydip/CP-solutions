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
#define rall(v) v.rbegin(), v.rend()
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);

    iv(a);
    iv(b);

    vector<bool> isTaken(m, 0);
    vi answer(m, -1);

    map<int, int> mp;
    // set< pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = INT_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] == INT_MAX)
        {
            mp[a[i]] = i + 1;
        }
        else
        {
            if (mp[a[i]] > i + 1)
            {
                mp[a[i]] = i + 1;
            }
        }
    }

    // print(mp);
    // // return;

    // for (int i = 0; i < m; i++)
    // {
    //     auto it = mp.lower_bound(b[i]);
    //     cout << "B[i]: " << b[i] << ", lowerB: " << (*it).first << ":" << (*it).second << "\n";
    //     if (it != mp.end())
    //     {
    //         answer[i] = (*it).second;
    //     }
    //     // auto it = upp
    // }
    // print(answer);

    vi pref;
    ll mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mini)
        {
            pref.push_back(a[i]);
            mini = a[i];
        }
    }

    // print(pref);

    for (int i = 0; i < m; i++)
    {
        // if (!isTaken[i])
        // {
        auto it = (upper_bound(rall(pref), b[i]));
        it--;
        // cout << "it: " << *it << endl;
        if (it == pref.rend())
        {
            answer[i] = 1;
            // cout << "No for: " << b[i] << endl;
        }
        else
        {
            if (mp[*it] != 0)
                answer[i] = mp[*it];
            // cout << "LowerB: " << mp[*it] << ", b[i]: " << b[i] << endl;
        }
        // answer[i] = mp[lb];

        // for (int j = 0; j < n; j++)
        // {
        //     if (b[i] >= a[j])
        //     {
        //         answer[i] = j + 1;
        //         isTaken[i] = 1;
        //         break;
        //     }
        // }
        // }
    }
    print(answer);
}
// -----------------------------------------------------------------------------------
int main()
{
    init;
    int t = 1;
    ;
    // cin >> t;
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
        cout << element << "\n";
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