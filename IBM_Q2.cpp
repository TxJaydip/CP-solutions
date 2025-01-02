#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int a1[n];
    for (int i = 0; i < n; i++)
        a1[i] = a[i];
    int answer1 = 0;
    // 1
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
                answer1++;
            }
        }
    }
    int answer2 = 0;
    // 2
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a1[i] > a1[j])
            {
                swap(a1[i], a1[j]);
                answer2++;
            }
        }
    }
    cout << min(answer1, answer2) << endl;
}