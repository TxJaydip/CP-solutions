#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;

typedef long long ll;

struct Result
{
    ll sum;
    int startIdx;
    int endIdx;
};

Result maxSubArray(vector<ll> &v)
{
    if (v.size() == 1 || v.size() == 2)
    {
        return {accumulate(v.begin(), v.end(), 0), 0, int(v.size()) - 1};
    }

    ll minSum = numeric_limits<ll>::max();
    int start = 0;
    int end = 0;
    ll currentSum = v[0] + v[1];

    for (int i = 1; i < v.size(); i++)
    {
        ll nextSum = i < v.size() - 1 ? v[i] + v[i + 1] : 0; // Next possible sum

        if (currentSum < minSum)
        {
            minSum = currentSum;
            start = i - 1;
            end = i;
        }

        if (v[i] < currentSum + v[i])
        {
            currentSum += v[i];
            if (v[i] < nextSum)
            {
                end = i;
            }
        }
        else
        {
            currentSum = v[i];
            if (v[i] < nextSum)
            {
                start = i;
                end = i;
            }
        }
    }

    // Adjust start index
    while (start > 0 && v[start - 1] + v[start] <= v[start])
    {
        start--;
    }

    return {minSum, start, end};
}

int main()
{
    vector<ll> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Result res = maxSubArray(arr);
    cout << "Least possible sum: " << res.sum << endl;
    cout << "Start index: " << res.startIdx << ", End index: " << res.endIdx << endl;
    return 0;
}
