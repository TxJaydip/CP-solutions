#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define vpi vector<pair<ll, ll>>
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
ll modex1(ll a, ll b);
ll mod(ll a, ll b);
// -----------------------------------------------------------------------------------
void solve()
{
    // ll n, m, l;
    // cin >> n >> m >> l;

    // vector<pair<ll, ll>> hurdles(n);
    // vector<pair<ll, ll>> powerUps(m);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> hurdles[i].first >> hurdles[i].second;
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> powerUps[i].first >> powerUps[i].second;
    // }

    // vector<pair<ll, ll>> req;
    // for (auto i : hurdles)
    // {
    //     ll diff = (i.second - i.first) + 2ll;
    //     pair<ll, ll> temp = {i.first - 1ll, diff};
    //     req.pb(temp);
    // }
    // priority_queue<ll> powerUpsPQ;
    // // cout << "PowerIps: ";
    // // print(powerUps);
    // // cout << "Require: ";
    // // print(req);

    // ll currentPower = 1;
    // ll nxtReqInd = req[0].first;
    // ll reqIndex = 0;
    // ll picked = 0;
    // ll powerUpIndex = 0;
    // ll powerupIndexFirst = powerUps[0].first;

    // ll indexIterat = min(nxtReqInd, powerupIndexFirst);

    // for (; indexIterat <= l;)
    // {
    //     if (indexIterat == powerupIndexFirst)
    //     {
    //         while (indexIterat == powerupIndexFirst)
    //         {
    //             powerUpsPQ.push(powerUps[powerUpIndex].second);
    //             powerUpIndex++;
    //             if (powerUpIndex == powerUps.size())
    //             {
    //                 powerUpIndex = -1;
    //                 powerupIndexFirst = -1;
    //             }
    //             else
    //                 powerupIndexFirst = powerUps[powerUpIndex].first;
    //         }
    //     }
    //     if (indexIterat == nxtReqInd)
    //     {
    //         // cout << "i: " << i << ", nxtReqInd: " << nxtReqInd << endl;
    //         if (currentPower < req[reqIndex].second)
    //         {
    //             while (!powerUpsPQ.empty() && currentPower < req[reqIndex].second)
    //             {
    //                 // cout << "Picked: " << powerUpsPQ.top() << ", ";
    //                 currentPower += powerUpsPQ.top();
    //                 // cout << "CurrentPower: " << currentPower << endl;
    //                 powerUpsPQ.pop();
    //                 picked++;
    //             }
    //             if (currentPower >= req[reqIndex].second)
    //             {
    //                 reqIndex++;
    //                 if (reqIndex == req.size())
    //                 {
    //                     cout << picked << endl;
    //                     return;
    //                 }
    //                 else
    //                 {
    //                     nxtReqInd = req[reqIndex].first;
    //                 }
    //             }
    //             else
    //             {
    //                 // cout << "Req: ";
    //                 // print(req);
    //                 // cout << "PowerUps: ";
    //                 // print(powerUps);
    //                 // cout << "Priority Queue: ";
    //                 // cout << "i: " << i << ", nxtReqInd: " << nxtReqInd << ", currPower: " << currentPower << ", req[i].sec: " << req[i].second << endl;
    //                 // while (!powerUpsPQ.empty())
    //                 // {
    //                 //     cout << powerUpsPQ.top() << ' ';
    //                 //     powerUpsPQ.pop();
    //                 // }
    //                 // cout << endl;
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //         else

    //         {
    //             reqIndex++;
    //             if (reqIndex == req.size())
    //             {
    //                 cout << picked << endl;
    //                 return;
    //             }
    //             else
    //             {
    //                 nxtReqInd = req[reqIndex].first;
    //             }
    //         }

    //         // cout << "Next Req Updated: " << reqIndex << endl;
    //     }
    //     if (powerupIndexFirst == -1)
    //     {
    //         if (nxtReqInd == -1)
    //         {
    //             cout << picked << endl;
    //             return;
    //         }
    //         indexIterat = nxtReqInd;
    //     }
    //     else
    //     {
    //         if (nxtReqInd == -1)
    //         {
    //             indexIterat = powerupIndexFirst;
    //         }
    //         else
    //         {
    //             indexIterat = min(powerupIndexFirst, nxtReqInd);
    //         }
    //     }
    // }

    // cout << picked << endl;
    // return;

    //  D ENDS HERE

    // C Starts here

    // ll n;
    // cin >> n;
    // if (n <= 4)
    // {
    //     cout << -1 << endl;
    //     return;
    // }

    // // if( n == 5 )
    // // {
    // //     cout<<""
    // // }

    // vi evens = {4, 2}, odds = {1, 3};
    // for (int i = 6; i <= n; i++)
    // {
    //     if (i % 2 == 1)
    //     {
    //         odds.pb(i);
    //     }
    //     else
    //     {
    //         evens.pb(i);
    //     }
    // }
    // odds.pb(5);
    // for (auto i : odds)
    // {
    //     cout << i << " ";
    // }
    // for (auto i : evens)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // return;

    // C ENDS HERE

    // B Starts Here

    ll k;
    cin >> k;
    vi v(k);
    iv(v);

    ll total = k - 2;
    unordered_map<int, int> mp;
    for (auto i : v)
    {
        mp[i]++;
    }
    // cout << "\n-------------" << endl;
    // print(mp);
    // cout << "Total: " << total << endl;
    // cout << "mp[1]: " << mp[1] << ", total%1: " << total % 1 << ", mp[total/1]: " << mp[total / 1] << endl;
    for (int i = 1; i <= total; i++)
    {
        if (mp[i] > 0 && total % i == 0 && mp[total / i])
        {
            cout << i << " " << total / i << endl;
            return;
        }
    }

    // B ENDS HERE

    // A Starts here

    // int n;
    // cin >> n;
    // vi v(n);
    // iv(v);
    // map<int, int> mp;
    // for (auto i : v)
    // {
    //     mp[i]++;
    // }
    // ll score = 0;
    // for (auto i : mp)
    // {
    //     score += (i.second / 2);
    // }
    // cout << score << endl;
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