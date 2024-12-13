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
    int r_bt;
    int prio;

    Process(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        id = a;
        at = b;
        bt = c;
        r_bt = c;
        prio = d;
    }
};

void fcfs(Process p[], int n)
{
    int curr = 0;
    int t_tat = 0;
    int t_wait = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i].at > curr)
        {
            curr = p[i].at;
        }

        curr += p[i].bt;
        p[i].ct = curr;
        p[i].tat = p[i].ct - p[i].at;
        t_tat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        t_wait += p[i].wt;
    }

    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)t_tat / n;
    float avg_wait = (float)t_wait / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;
}

void round_robin(Process p[], int n, int tq)
{
    int curr = 0;
    int t_tat = 0;
    int t_wait = 0;
    int completed = 0;
    vector<bool> isComleted(n, false);

    while (completed < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!isComleted[i] && p[i].at <= curr)
            {
                found = true;
                if (p[i].r_bt <= tq)
                {
                    curr += p[i].r_bt;
                    p[i].ct = curr;
                    p[i].tat = p[i].ct - p[i].at;
                    t_tat += p[i].tat;
                    p[i].wt = p[i].tat - p[i].bt;
                    t_wait += p[i].wt;
                    isComleted[i] = true;
                    completed++;
                }

                else
                {
                    curr += tq;
                    p[i].r_bt -= tq;
                }
            }
        }

        if (!found)
        {
            curr++;
        }
    }

    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)t_tat / n;
    float avg_wait = (float)t_wait / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;
}

void sjf(Process p[], int n)
{
    int curr = 0;
    int completed = 0;
    int t_tat = 0;
    int t_wait = 0;
    vector<bool> isComleted(n, false);
    while (completed < n)
    {
        int idx = -1;
        int shortest_bt = 9999999;

        for (int i = 0; i < n; i++)
        {
            if (!isComleted[i] && p[i].at <= curr && p[i].bt < shortest_bt)
            {
                idx = i;
                shortest_bt = p[i].bt;
            }
        }

        if (idx != -1)
        {
            curr += p[idx].bt;
            p[idx].ct = curr;
            p[idx].tat = p[idx].ct - p[idx].at;
            t_tat += p[idx].tat;
            p[idx].wt = p[idx].tat - p[idx].bt;
            t_wait += p[idx].wt;
            completed++;
            isComleted[idx] = true;
        }

        else
        {
            curr++;
        }
    }

    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)t_tat / n;
    float avg_wait = (float)t_wait / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;
}

void non_preemptive_priority(Process p[], int n)
{
    int curr = 0;
    int t_tat = 0;
    int t_wait = 0;

    int completed = 0;
    vector<bool> isCompleted(n, false);

    while (completed < n)
    {
        int idx = -1;
        int temp = 99999;
        for (int i = 0; i < n; i++)
        {
            if ((!isCompleted[i]) && (p[i].at <= curr) && (p[i].prio < temp))
            {
                idx = i;
                temp = p[i].prio;
            }
        }

        if (idx != -1)
        {
            curr += p[idx].bt;
            p[idx].ct = curr;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            t_tat += p[idx].tat;
            t_wait += p[idx].wt;
            completed++;
            isCompleted[idx] = true;
        }

        else
        {
            curr++;
        }
    }
    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)t_tat / n;
    float avg_wait = (float)t_wait / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;
}

void preemtive_priority(Process p[], int n)
{
    int curr = 0;
    int t_tat = 0;
    int t_wait = 0;
    int completed = 0;
    vector<bool> isCompleted(n, false);

    while (completed < n)
    {
        int idx = -1;
        int temp = 999999;
        for (int i = 0; i < n; i++)
        {
            if ((!isCompleted[i]) && (p[i].at <= curr) && (p[i].prio < temp))
            {
                idx = i;
                temp = p[i].prio;
            }
        }

        if (idx != -1)
        {
            curr++;
            p[idx].r_bt--;

            if (p[idx].r_bt == 0)
            {
                p[idx].ct = curr;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                t_tat += p[idx].tat;
                t_wait += p[idx].wt;
                completed++;
                isCompleted[idx] = true;
            }
        }

        else
        {
            curr++;
        }
    }
    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << p[i].id << "\t    " << p[i].at << "\t\t   " << p[i].bt << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }
    float avg_tat = (float)t_tat / n;
    float avg_wait = (float)t_wait / n;
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
    preemtive_priority(p, n);
}