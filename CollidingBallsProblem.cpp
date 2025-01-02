#include "bits/stdc++.h"
using namespace std;
#define ll long long int

void iv(vector<ll> &pos, vector<ll> &speed)
{
    ll POS, SPEED;
    for (int i = 0; i < pos.size(); i++)
    {
        cin >> POS >> SPEED;
        pos[i] = POS;
        speed[i] = SPEED;
    }
}

bool doesCollide(ll posX, ll speedX, ll posY, ll speedY)
{
    if (posX * speedX == posY * speedY)
    {
        return 1;
    }
    return 0;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> posX(n), posY(m), speedX(n), speedY(m);
    iv(posX, speedX);
    iv(posY, speedY);

    // set<ll> excludedX;
    // set<ll> excludedY;

    // ll answer = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (excludedX.find(i) != excludedX.end())
    //     {
    //         continue;
    //     }
    //     ll mul = posX[i] * speedX[i];
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (excludedY.find(j) != excludedY.end())
    //         {
    //             continue;
    //         }
    //         if (mul == posY[j] * speedY[j])
    //         {
    //             answer++;
    //             excludedY.insert(j);
    //             excludedX.insert(i);
    //             break;
    //         }
    //     }
    // }

    // cout << answer << endl;

    vector<ll> xMultiples(n);
    vector<ll> yMultiples(m);
    map<ll, ll> xMultiplesMap;
    map<ll, ll> yMultiplesmap;
    for (int i = 0; i < n; i++)
        xMultiples[i] = posX[i] * speedX[i];
    for (int i = 0; i < m; i++)
        yMultiples[i] = posY[i] * speedY[i];
    for (auto i : xMultiples)
        xMultiplesMap[i]++;
    for (auto i : yMultiples)
        yMultiplesmap[i]++;

    ll answer = 0;
    for (auto i : xMultiples)
    {
        if (xMultiplesMap[i] > 0 && yMultiplesmap[i] > 0)
        {
            answer++;
            xMultiplesMap[i]--;
            yMultiplesmap[i]--;
        }
    }
    cout << answer << endl;

    return 0;
}