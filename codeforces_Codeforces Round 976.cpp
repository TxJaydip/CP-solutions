#include "bits/stdc++.h"
using namespace std;

#define ll long long unsigned int
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
// -----------------------------------------------------------------------------------

// Modified from GeeksFromGeeks
// Function to find the ceiling of the square root

int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

ll floorSqrt(ll x)
{
    if (x == 0 || x == 1)
        return x;
    ll start = 1, end = x, ans = 0;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (mid * mid == x)
            return mid;
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
bool isPerfectSquare(ll x)
{
    if (x < 0)
        return false;
    if (x == 0 || x == 1)
        return true;
    ll start = 1, end = x;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        ll square = mid * mid;

        if (square == x)
            return true;
        else if (square < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    // cin >> n;
    int a = 0;

    // cout << n + floorSqrt(n) << endl;
    // return;
    // cout << "Square Root: " << floorSqrt(n) << endl;
    // ll sqFound = floorSqrt(n);
    // cout << "Floor Sqrt: " << floorSqrt(n) << endl;
    // cout << "Org Sqrt:   " << (ll)sqrtl((ll)n) << endl;
    // ll pre = sqFound;
    // ll curr = floorSqrt(n + pre);
    // if (pre != curr)
    // {
    //     cout << n + pre + 1 << endl;
    // }
    // else
    // {
    //     cout << n + pre << endl;
    // }

    ll sqFound = (ll)sqrtl((ll)n);
    // cout << "Floor Sqrt: " << floorSqrt(n) << endl;
    // cout << "Org Sqrt:   " << (ll)sqrtl((ll)n) << endl;
    ll pre = sqFound;
    ll curr = (ll)sqrtl((ll)(n + pre));
    if (pre != curr)
    {
        cout << n + pre + 1 << endl;
    }
    else
    {
        cout << n + pre << endl;
    }

    // cout << n + floorSqrt(n1) << endl;
    return;
    // if (isPerfectSquare(sqFound + n))
    // {
    //     cout << n + sqFound + 1 << endl;
    // }
    // else
    // {
    //     cout << n + sqFound << endl;
    // }

    // cout << n << ": " << n + floorSqrt(n) << endl;
    for (int i = 1; i < 100; i++)
    {
        cout << i << ": ";
        if (countDivisors(i) % 2 == 0)
        {
            a++;
        }
        cout << a << endl;
    }

    // ll n, k;
    // cin >> n >> k;
    // ll ans = 0;
    // if (k == 1)
    // {
    //     cout << n << endl;
    //     return;
    // }
    // while (n > 0)
    // {
    //     if (n == k)
    //     {
    //         ans++;
    //         break;
    //     }
    //     if (n < k)
    //     {
    //         ans += n;
    //         break;
    //     }
    //     ll k1 = 1;
    //     while (k1 <= n)
    //     {
    //         k1 *= k;
    //     }
    //     k1 /= k;
    //     n -= k1;
    //     ans++;
    // }

    // cout << ans << endl;
}
// -----------------------------------------------------------------------------------
int main()
{
    init;
    // cout << "Squares: " << sqrtl(10000000000000) << endl;
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