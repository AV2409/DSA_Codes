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
    int prio;
    int r_bt;
    Process(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        id = a;
        at = b;
        bt = c;
        r_bt = c;
        prio = d;
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
        int idx = -1;
        int prio_num = 99999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currentTime && (!isCompleted[i]) && p[i].prio < prio_num)
            {
                idx = i;
                prio_num = p[i].prio;
            }
        }

        if (idx != -1)
        {

            p[idx].r_bt--;
            currentTime++;

            if (p[idx].r_bt == 0)
            {
                p[idx].ct = currentTime;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                totalTat += p[idx].tat;
                totalWt += p[idx].wt;
                isCompleted[idx] = true;
                completed++;
            }
        }

        else
        {
            currentTime++;
        }
    }

    cout << "Process\t  Arrival\t  Priority\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].prio << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)totalTat / n;
    float avg_wait = (float)totalWt / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;
}

int main()
{
    Process p[5];
    p[0] = Process(1, 0, 3, 3);
    p[1] = Process(2, 1, 4, 2);
    p[2] = Process(3, 2, 6, 4);
    p[3] = Process(4, 3, 4, 6);
    p[4] = Process(5, 5, 2, 10);
    int n = 5;
    calculate(p, n);

    return 0;
}
