#include "bits/stdc++.h"
using namespace std;

string token = "hxwosd46";

int MathChallenge(int num)
{
    int ans = 0;
    while (true)
    {
        vector<int> nums;
        while (num > 0)
        {
            nums.push_back(num % 10);
            num /= 10;
        }
        if (nums.size() == 1)
        {
            break;
        }
        ans++;
        num = accumulate(nums.begin(), nums.end(), 0);
    }
    return ans;
}

// string mathChallenge(int num1, int num2)
// {
//     int ans1 = ceil((long double)(num1) / (long double)(num2));
//     string s = to_string(ans1);
//     string ans = "";
//     reverse(s.begin(), s.end());
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (i % 3 == 0 && i != 0)
//         {
//             ans.push_back(',');
//         }
//         ans.push_back(s[i]);
//     }
//     ans += ":";
//     string temp_token = token;
//     reverse(temp_token.begin(), temp_token.end());
//     ans += temp_token;
//     return ans;
// }

int main()
{
    int n1;
    cin >> n1;
    cout << MathChallenge(n1) << endl;
}