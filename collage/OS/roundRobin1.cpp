#include <bits/stdc++.h>
using namespace std;

#define tq 2

class Process
{
public:
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int r_bt;

    Process(int a = 0, int b = 0, int c = 0)
    {
        id = a;
        at = b;
        bt = c;
        r_bt = c;
    }
};

void calculate(Process p[], int n)
{
    int currentTime = 0;
    int completed = 0;
    int totalTat = 0;
    int totalWt = 0;
    vector<bool> isCompleted(n, false);

    while (completed < n)
    {
        bool foundProcess = false;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currentTime && !isCompleted[i])
            {
                foundProcess = true;

                if (p[i].r_bt <= tq)
                {
                    currentTime += p[i].r_bt;
                    p[i].ct = currentTime;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;

                    totalTat += p[i].tat;
                    totalWt += p[i].wt;

                    p[i].r_bt = 0;
                    isCompleted[i] = true;
                    completed++;
                }
                else
                {
                    currentTime += tq;
                    p[i].r_bt -= tq;
                }
            }
        }

        if (!foundProcess)
        {
            currentTime++;
        }
    }

    cout << "Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t   " << p[i].at << "\t"
             << p[i].bt << "\t\t" << p[i].ct << "\t\t"
             << p[i].tat << "\t\t" << p[i].wt << endl;
    }

    float avg_tat = (float)(totalTat) / n;
    float avg_wait = (float)(totalWt) / n;

    cout << endl
         << "Average Waiting Time: " << avg_wait;
    cout << endl
         << "Average Turnaround Time: " << avg_tat << endl;
}

int main()
{
    Process p[4];
    p[0] = Process(1, 0, 5);
    p[1] = Process(2, 1, 4);
    p[2] = Process(3, 2, 2);
    p[3] = Process(4, 4, 1);

    int n = 4;
    calculate(p, n);

    return 0;
}