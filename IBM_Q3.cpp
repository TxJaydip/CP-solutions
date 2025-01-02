#include "bits/stdc++.h"
using namespace std;

#define ll long long int

ll binToDec(string s)
{
    ll dec_num = 0;
    ll power = 0;
    ll n = s.length();
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            dec_num += (1 << power);
        }
        power++;
    }
    return dec_num;
}

void printSubsequence(string input, string output, unordered_set<int> &answer)
{
    if (input.empty())
    {
        answer.insert(binToDec(output));
        return;
    }

    printSubsequence(input.substr(1), output + input[0], answer);
    printSubsequence(input.substr(1), output, answer);
}

int main()
{
    string s;
    cin >> s;
    unordered_set<int> answer;
    printSubsequence(s, "", answer);
    cout << answer.size() << endl;

    return 0;
}