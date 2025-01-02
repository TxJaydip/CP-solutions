#include "bits/stdc++.h"
using namespace std;

void bullyElection(vector<int> processes, int initiator)
{
    int n = processes.size();
    for (int i = 0; i < n; i++)
    {
        if (processes[i] > initiator && processes[i] != -1)
        {
            cout << "Process " << initiator << " sends message to process " << processes[i] << endl;
        }
    }

    int leader = -1;
    for (int i = 0; i < n; i++)
    {
        if (processes[i] > initiator)
        {
            cout << "PRocess " << processes[i] << " replieds to process " << initiator << endl;
            leader = max(leader, processes[i]);
        }
    }
    if (leader == -1)
    {
        leader = initiator;
    }

    cout << "Final Leader is process " << leader << endl;
    return;
}

int main()
{
    cout << "Enter no. of processes: ";
    int n;
    cin >> n;
    vector<int> process(n);
    cout << "Enter processes' ids(-1 if a process is crashed or down): ";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i];
    }
    int initiator;
    cout << "Enter initiator: ";
    cin >> initiator;

    bullyElection(process, initiator);

    return 0;
}