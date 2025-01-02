// Lamport :
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(int e1, int e2, int p1[], int p2[])
{
    int i;
    cout << "\nTime stamps of events in P1 : " << endl;
    for (i = 0; i < e1; i++)
    {
        cout << p1[i] << " ";
    }
    cout << "\nTime stamps of events in P2 : " << endl;
    for (i = 0; i < e2; i++)
    {
        cout << p2[i] << " ";
    }
}
void lamportLogicalClock(int e1, int e2, vector<vector<int>> m)
{
    int i, j, k;
    int p1[e1], p2[e2];
    for (i = 0; i < e1; i++)
        p1[i] = i + 1;
    for (i = 0; i < e2; i++)
        p2[i] = i + 1;
    for (i = 0; i < e1; i++)
    {
        for (j = 0; j < e2; j++)
        {
            if (m[i][j] == 1)
            {
                p2[j] = max(p2[j], p1[i] + 1);
                for (k = j + 1; k < e2; k++)
                    p2[k] = p2[k - 1] + 1;
            }
            if (m[i][j] == -1)
            {
                p1[i] = max(p1[i], p2[j] + 1);
                for (k = i + 1; k < e1; k++)
                    p1[k] = p1[k - 1] + 1;
            }
        }
    }
    display(e1, e2, p1, p2);
}
int main()
{
    int e1, e2;
    cout << "Enter the number of events for P1 : ";
    cin >> e1;
    cout << "Enter the number of events for P2 : ";
    cin >> e2;
    vector<vector<int>> m(e1, vector<int>(e2));
    cout << "\nEnter the dependencies matrix :" << endl;
    for (int i = 0; i < e1; i++)
    {
        for (int j = 0; j < e2; j++)
        {
            cin >> m[i][j];
        }
    }
    lamportLogicalClock(e1, e2, m);
    return 0;
}