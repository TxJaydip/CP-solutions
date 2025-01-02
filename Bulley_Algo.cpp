// Bulley Algo:
#include <bits/stdc++.h>
using namespace std;

void bullyElection(vector<int> &processes, int initiator)
{
    int leader = -1;

    cout << "Election initiated by process " << initiator << endl;

    for (int i = 0; i < processes.size(); i++)
    {
        if (processes[i] > initiator && processes[i] != -1)
        {
            cout << "Process " << initiator << " sends election message to process " << processes[i] << endl;
        }
    }

    for (int i = 0; i < processes.size(); i++)
    {
        if (processes[i] > initiator && processes[i] != -1)
        {
            cout << "Process " << processes[i] << " replies to process " << initiator << endl;
            leader = max(leader, processes[i]);
        }
    }

    if (leader == -1)
    {
        leader = initiator;
    }
    else
    {
        for (int id : processes)
        {
            if (id > leader && id != -1)
            {
                leader = id;
            }
        }
    }

    cout << "The new leader is process " << leader << endl;
}

int main()
{
    int numProcesses;
    cin >> numProcesses;
    vector<int> processes(numProcesses);
    for (int i = 0; i < numProcesses; i++)
    {
        cin >> processes[i];
    }

    int initiator;
    cin >> initiator;

    if (find(processes.begin(), processes.end(), initiator) == processes.end() || initiator == -1)
    {
        cout << "Invalid initiating process or process is down!" << endl;
        return 1;
    }

    bullyElection(processes, initiator);
    return 0;
}