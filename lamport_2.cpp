#include "bits/stdc++.h"
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
}

void printvector(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";

    cout << endl;
}

int main()
{
    int p1;
    int p2;
    cout << "Enter no. of events in P1: ";
    cin >> p1;
    cout << "Enter no. of events in P2: ";
    cin >> p2;

    vector<vector<int>> dependencyMatrix(p1, vector<int>(p2));

    cout << "Enter dependency Matrix:\n";
    for (int i = 0; i < p1; i++)
    {
        for (int j = 0; j < p2; j++)
        {
            cin >> dependencyMatrix[i][j];
        }
    }

    vector<int> process1(p1);
    vector<int> process2(p2);
    for (int i = 0; i < max(p1, p2); i++)
    {
        i < p1 ? process1[i] = i + 1 : 0;
        i < p2 ? process2[i] = i + 1 : 0;
    }
    // printvector(process1);
    // printvector(process2);

    for (int i = 0; i < p1; i++)
    {
        for (int j = 0; j < p2; j++)
        {
            if (dependencyMatrix[i][j] == 1)
            {
                // We have to modify P2's jth node
                // with maximum of p2[j], 1 + p1[i]
                int currentP1 = process1[i];
                int currentp2 = process2[j];
                int maximumOfTwo = max(currentp2, 1 + currentP1);

                process2[j] = maximumOfTwo;
                // after that make sure remaining P2's timestamps are
                // are in increasing order from where we have modified it
                for (int k = j + 1; k < p2; k++)
                {
                    process2[k] = max(process2[k], 1 + process2[k - 1]);
                }
            }
            else if (dependencyMatrix[i][j] == -1)
            {
                // We have to modify P1's ith node
                // with maximum of p1[i], 1 + p2[j]
                int currentP1 = process1[i];
                int currentP2 = process2[j];
                int maximumOfTwo = max(currentP1, 1 + currentP2);
                process1[i] = maximumOfTwo;

                // after that make sure remaining P1's timestamps are
                // in increasing order from where we have modified it
                for (int k = i + 1; k < p1; k++)
                {
                    process1[k] = max(process1[k], process1[k - 1] + 1);
                }
            }
        }
    }

    cout << "Final Timestamps of processes: \n";
    cout << "Process 1: ";
    printvector(process1);
    cout << "Process 2: ";
    printvector(process2);

    return 0;
}