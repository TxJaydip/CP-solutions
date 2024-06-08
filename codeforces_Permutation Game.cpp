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

class seq
{
public:
    ll ind;
    ll nxt;
    ll score;
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, pb, ps;
        cin >> n >> k >> pb >> ps;
        vi p;
        vi a;
        iv(p, n);
        iv(a, n);

        ll i = pb - 1;
        vector<seq> bodya;
        seq temp;
        temp.nxt = p[i];
        temp.score = a[i];
        temp.ind = i + 1;
        bodya.pb(temp);
        while (true)
        {
            if (bodya[0].ind == temp.nxt)
            {
                break;
            }
            else
            {
                temp.ind = temp.nxt;
                temp.nxt = p[temp.ind - 1];
                temp.score = a[temp.ind - 1];
                bodya.pb(temp);
            }
        }

        i = ps - 1;
        vector<seq> sasha;
        temp.nxt = p[i];
        temp.score = a[i];
        temp.ind = i + 1;
        sasha.pb(temp);
        while (true)
        {
            if (sasha[0].ind == temp.nxt)
            {
                break;
            }
            else
            {
                temp.ind = temp.nxt;
                temp.nxt = p[temp.ind - 1];
                temp.score = a[temp.ind - 1];
                sasha.pb(temp);
            }
        }
        // cout << "---------------\nBodya: ";
        // for (auto i : bodya)
        // {
        //     cout << i.score << " ";
        // }
        // cout << endl
        //      << "Sasha: ";
        // for (auto i : sasha)
        // {
        //     cout << i.score << " ";
        // }
        // cout << endl;

        vector<ll> prefixB(bodya.size());
        vector<ll> prefixS(sasha.size());

        prefixB[0] = bodya[0].score;
        prefixS[0] = sasha[0].score;

        for (ll i = 1; i < bodya.size(); i++)
        {
            prefixB[i] = bodya[i].score + prefixB[i - 1];
        }

        for (ll i = 1; i < sasha.size(); i++)
        {
            prefixS[i] = sasha[i].score + prefixS[i - 1];
        }

        // bodya max cal
        ll ansB = bodya[0].score * k;
        ll tempSum = 0;
        for (ll i = min(int(bodya.size()) - 1, int(k)); i >= 0; i--)
        {
            while (bodya[i].score < bodya[0].score)
            {
                i--;
            }
            tempSum = prefixB[i] + (k - (i + 1)) * bodya[i].score;
            ansB = max(ansB, tempSum);
        }

        // sasha max cal
        ll ansS = sasha[0].score * k;
        tempSum = 0;
        for (ll i = min(int(sasha.size()) - 1, int(k)); i >= 0; i--)
        {
            while (sasha[i].score < sasha[0].score)
            {
                i--;
            }
            tempSum = prefixS[i] + (k - (i + 1)) * sasha[i].score;
            ansS = max(ansS, tempSum);
        }

        if (ansB > ansS)
        {
            cout << "Bodya";
        }
        else if (ansS > ansB)
        {
            cout << "Sasha";
        }
        else
        {
            cout << "Draw";
        }
        cout << endl;
        // cout << "\t ansB: " << ansB << ", ansS: " << ansS << endl;
    }
    return 0;
}