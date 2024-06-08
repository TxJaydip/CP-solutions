#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum possible maximum of the array after performing at most k operations.
int findMaxAfterOperations(int n, int k, vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
        while (arr[i] < max_val && k > 0) {
            arr[i]++;
            k--;
        }

        max_val = max(max_val, arr[i]);
    }

    return max_val;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = findMaxAfterOperations(n, k, arr);
        cout << result << endl;
    }

    return 0;
}

