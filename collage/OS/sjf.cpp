#include <bits/stdc++.h>
using namespace std;
class Process
{
public:
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;

    Process(int a = 0, int b = 0, int c = 0)
    {
        id = a;
        at = b;
        bt = c;
    }
};

void calculate(Process p[], int n)
{

    int currentTime = 0; // Current time tracker
    int completed = 0;   // Number of completed processes
    int total_tat = 0;   // Total turnaround time
    int total_wt = 0;    // Total waiting time

    vector<bool> isCompleted(n, false); // Track which processes are completed

    while (completed < n)
    {
        int idx = -1;
        int shortest_bt = 999999;

        // Select the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++)
        {
            if ((p[i].at <= currentTime) && (!isCompleted[i]) && (p[i].bt < shortest_bt))
            {
                shortest_bt = p[i].bt;
                idx = i;
            }
        }

        if (idx != -1)
        {
            // Process found, so we execute it
            currentTime += p[idx].bt;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at; // Turnaround time
            p[idx].wt = p[idx].tat - p[idx].bt; // Waiting time

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            isCompleted[idx] = true;
            completed++;
        }
        else
        {
            // If no process has arrived, increment the current time
            currentTime = p[completed].at;
        }
    }

    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)total_tat / n;
    float avg_wait = (float)total_wt / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;
}

int main()
{
    Process p[5];
    p[0] = Process(1, 2, 6);
    p[1] = Process(2, 5, 2);
    p[2] = Process(3, 1, 8);
    p[3] = Process(4, 0, 3);
    p[4] = Process(5, 4, 4);
    int n = 5;
    calculate(p, n);

    return 0;
}