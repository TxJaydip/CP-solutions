#include "bits/stdc++.h"
using namespace std;

void mergeSortConq(vector<int> &v, int st, int mid, int ed)
{
    vector<int> temp(ed - st + 1);
    int i = st;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= ed)
    {
        if (v[i] < v[j])
        {
            temp[k] = v[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = v[j];
            j++;
            k++;
        }
    }

    while (j <= ed)
    {
        temp[k] = v[j];
        j++;
        k++;
    }
    while (i <= mid)
    {
        temp[k] = v[i];
        i++;
        k++;
    }
    int i2 = st;
    for (int i1 = 0; i1 < temp.size(); i1++)
    {
        v[i2] = temp[i1];
        i2++;
    }
}

void mergeSortDivide(vector<int> &v, int st, int ed)
{
    if (st >= ed)
    {
        return;
    }
    int mid = st + ((ed - st) / 2);
    mergeSortDivide(v, st, mid);
    mergeSortDivide(v, mid + 1, ed);

    mergeSortConq(v, st, mid, ed);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    mergeSortDivide(v, 0, n - 1);
    cout << "Sorted: ";
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}