//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    vector<int> diagnosis(int n, vector<int> &time, vector<int> &weak)
    {
        vector<int> doneTreamentFor(n, 0);
        int maxTime = *max_element(time.begin(), time.end());
        priority_queue<int> p;

        int j = 0;
        for(int i = 1;i<=maxTime;i++)
        {
            if( j < n && time[j] >= i )
            {
                p.push(j);
            }
        }

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> time(n);
        Array::input(time, n);

        vector<int> weak(n);
        Array::input(weak, n);

        Solution obj;
        vector<int> res = obj.diagnosis(n, time, weak);

        Array::print(res);
    }
}

// } Driver Code Ends