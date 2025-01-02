//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

template <typename Container>
void print(const Container &container)
{
    for (const auto &element : container)
    {
        cout << element << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<vector<int>> prefS;
    vector<vector<int>> prefT;
    string SS;
    string TT;
    void makePref(string s, string t)
    {
        vector<int> s1(26, 0);
        vector<int> t1(26, 0);

        prefS.push_back(s1);
        prefT.push_back(t1);

        for (auto i : s)
        {
            s1[i - 'a']++;
            prefS.push_back(s1);
        }
        for (auto i : t)
        {
            t1[i - 'a']++;
            prefT.push_back(t1);
        }
    }

    bool isVecEqual(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isAnagram(int st, int ed)
    {
        vector<int> forS(26, 0);
        vector<int> forT(26, 0);

        vector<int> edVecS = prefS[ed + 1];
        vector<int> stVecS = prefS[st];
        // print(edVecS);
        // print(stVecS);
        vector<int> edVecT = prefT[ed + 1];
        vector<int> stVecT = prefT[st];

        for (int i = 0; i < 26; i++)
        {
            forS[i] = edVecS[i] - stVecS[i];
        }
        for (int i = 0; i < 26; i++)
        {
            forT[i] = edVecT[i] - stVecT[i];
        }
        // print(forS);
        // print(forT);
        if (isVecEqual(forS, forT))
        {
            return true;
        }

        return false;
    }
    int maxSplits(string s, string t)
    {
        SS = s;
        TT = t;
        makePref(s, t);
        // cout << "inside fun, s: " + s + ", t: " + t;
        string s1, s2, t1, t2;
        int answer = 0;
        // cout << "S: " << endl;
        // cout << "T: " << t << endl;
        for (int i = 0; i < s.length();)
        {
            for (int j = i; j < s.length(); j++)
            {
                s1 = s.substr(i, j - i + 1);
                int st = i, ed = j;

                if (j != s.length() - 1)
                {
                    s2 = s.substr(j + 1);
                    t2 = t.substr(j + 1);
                }
                else
                {
                    s2 = "";
                    t2 = "";
                }
                t1 = t.substr(i, j - i + 1);
                // cout << "s1: " + s1 + ", t1: " + t1 + ", s2: " + s2 + ", t2: " + t2 << endl;
                if (isAnagram(st, ed) && (isAnagram(st, ed)))
                {
                    // cout << "St: " << st << ", ed: " << ed << endl;
                    // cout << "inside anagram, s1: " + s1 + ", t1: " + t1 + ", s2: " + s2 + ", t2: " + t2 << endl;
                    answer++;
                    i = j + 1;
                    break;
                }
                if (j == s.length() - 1)
                {
                    answer++;
                    i = s.length();
                    break;
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    while (t--)
    {

        string s = "aaabc";

        string t = "aaacb";

        Solution obj;
        int res = obj.maxSplits(s, t);

        cout << res << endl;
    }
}
