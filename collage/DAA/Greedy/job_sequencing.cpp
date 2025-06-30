#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    char id;
    int deadline;
    int profit;

    Job(char x, int y, int z)
    {
        id = x;
        deadline = y;
        profit = z;
    }

    void print()
    {
        cout << id << " " << deadline << " " << profit << endl;
    }
};

bool comp(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

void JobSequencing(Job arr[], int n)
{
    sort(arr, arr + n, comp);

    for (int i = 0; i < n; i++)
    {
        arr[i].print();
    }

    char sequence[n + 1] = {0};
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int j = arr[i].deadline;
        while (j > 0)
        {
            if (sequence[j] == 0)
            {
                sequence[j] = arr[i].id;
                profit += arr[i].profit;
                break;
            }
            j--;
        }
    }
    cout << endl;
    cout << "Optimal sequence: ";
    for (int i = 0; i < n + 1; i++)
    {
        if (sequence[i] != 0)
        {
            cout << sequence[i] << " ";
        }
    }
    cout << endl
         << "Max profit: " << profit << endl;
}

int main()
{
    Job arr[] = {Job('a', 4, 20), Job('b', 1, 10), Job('c', 1, 40), Job('d', 1, 30)};
    int n = 4;
    JobSequencing(arr, n);
    return 0;
}
