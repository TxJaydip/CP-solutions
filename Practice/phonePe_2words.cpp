#include "bits/stdc++.h"
using namespace std;

int fun(unordered_map<char, int> mpWord, string s1, string s2, int ans, int flag)
{
    if(flag == 1)
    {
        
    }
    else
    {

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    string word;
    string s1;
    string s2;
    cin >> word;
    cin >> s1 >> s2;

    unordered_map<char, int> mpWord, mp1, mp2;
    for(auto i:word)
    {
        mpWord[i]++;
    }
    for(auto i:s1)
    {
        mp1[i]++;
    }
    for(auto i:s2)
    {
        mp2[i]++;
    }

    long long ans = 



    return 0;
}