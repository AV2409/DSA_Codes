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
    int total = 0;
    int t_tat = 0;
    int t_wait = 0;
    for (int i = 0; i < n; i++)
    {
        total += p[i].bt;
        p[i].ct = total;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        t_tat += p[i].tat;
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

int main()
{
    Process p[3];
    p[0] = Process(1, 0, 5);
    p[1] = Process(2, 1, 1);
    p[2] = Process(3, 2, 7);
    int n = 3;
    calculate(p, n);

    return 0;
}