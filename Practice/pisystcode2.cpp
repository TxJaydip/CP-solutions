#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back

int main()
{
    string f, l;
    cout << "Enter first name and last name separated by space: ";
    // string s;
    // getline(cin, s);

    cin >> f >> l;

    unordered_map<char, int> mp;
    for (char i : f)
    {
        mp[i]++;
    }
    for (char i : l)
    {
        mp[i]++;
    }

    cout << "First Name + (reversed)Last Name: ";

    reverse(l.begin(), l.end());
    cout << f << " " << l << endl;

    cout << "\nLetters' occurances: \n";
    for (auto i : mp)
    {
        cout << i.first << ": " << i.second << endl;
    }
    return 0;
}