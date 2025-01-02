#include "bits/stdc++.h"
using namespace std;

int n, m, p;

void printVector(vector<int> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> &answer)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << answer[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<vector<int>> addAllCs(vector<vector<int>> &c1, vector<vector<vector<int>>> &remainingCs)
{
    vector<vector<int>> allCsSum = c1;

    for (auto eachC : remainingCs)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                allCsSum[i][j] += eachC[i][j];
            }
        }
    }
    return allCsSum;
}

vector<vector<vector<int>>> normalPminusOneShifts(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<vector<vector<int>>> remainingCs;
    for (int ip = 0; ip < p - 1; ip++)
    {
        vector<vector<int>> currentC(n, vector<int>(m));

        // transforming A
        for (int i = 0; i < n; i++)
        {
            vector<int> currentRow = A[i];
            for (int j = 0; j < m; j++)
            {
                A[i][j] = currentRow[(j + 1) % m];
            }
        }

        // transforming B
        for (int i = 0; i < m; i++)
        {
            vector<int> currentColumn;
            for (int ii = 0; ii < n; ii++)
            {
                currentColumn.push_back(B[ii][i]);
            }

            for (int j = 0; j < n; j++)
            {
                B[j][i] = currentColumn[(j + 1) % n];
            }
        }

        // Adding A and B for C
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                currentC[i][j] = A[i][j] * B[i][j];
            }
        }
        remainingCs.push_back(currentC);
    }
    return remainingCs;
}

vector<vector<int>> initialShift(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<vector<int>> C(n, vector<int>(m));

    // left shifting on A

    for (int i = 0; i < n; i++)
    {
        vector<int> currentRow = A[i];
        for (int j = 0; j < m; j++)
        {
            A[i][j] = currentRow[(j + i) % m];
        }
    }

    // up shift on B
    for (int i = 0; i < m; i++)
    {
        vector<int> currentColumn;
        for (int ii = 0; ii < n; ii++)
        {
            currentColumn.push_back(B[ii][i]);
        }

        for (int j = 0; j < n; j++)
        {
            B[j][i] = currentColumn[(j + i) % n];
        }
    }

    // Adding A and B for C1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
    return C;
}

int main()
{
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    p = sqrt(n * m);

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));

    cout << "Enter matrix A row-by-row: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B row-by-row: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> c1 = initialShift(A, B);
    vector<vector<vector<int>>> remainingCs = normalPminusOneShifts(A, B);
    vector<vector<int>> answer = addAllCs(c1, remainingCs);
    print(answer);

    return 0;
}