#include <bits/stdc++.h>

using namespace std;

bool find(queue<int> q, int key)
{
    while (!q.empty())
    {
        int front = q.front();
        if (front == key)
        {
            return 1;
        }
        q.pop();
    }
    return 0;
}

void fifoPageReplacement(int pages[], int n, int capacity)
{
    queue<int> pageQueue;
    int hit = 0;
    int miss = 0;
    int en = 0;
    int de = 0;

    for (int i = 0; i < n; i++)
    {

        if (find(pageQueue, pages[i]))
        {
            hit++;
        }
        if (!find(pageQueue, pages[i]))
        {
            if (pageQueue.size() == capacity)
            {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                de++;
            }

            pageQueue.push(pages[i]);
            en++;
            miss++;
        }
    }
    queue<int> temp = pageQueue;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    cout << "Total Misses: " << miss << endl;
    cout << "Total Hits: " << hit << endl;
    cout << "Total enqueue: " << en << endl;
    cout << "Total dequeue: " << de << endl;
}

int main()
{
    int pages[] = {1, 2, 2, 1, 1, 3, 1, 1, 4, 1, 2, 6, 8, 8, 1, 1, 2, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 5;

    fifoPageReplacement(pages, n, capacity);

    return 0;
}