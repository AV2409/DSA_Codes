#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int n)
    {
        s1.push(n);
    }
    void dequeue()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    bool isEmpty()
    {
        if (s1.empty() && s2.empty())
        {
            return 1;
        }
        return 0;
    }

    int peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    void print()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        while (!s2.empty())
        {
            cout << s2.top() << "\t";
            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main()
{
    Queue st;
    bool x = true;
    while (x)
    {
        cout << "\n1. enqueue()\n2. dequeue()\n3. isEmpty()\n4. isFull()\n5. display()\n6. peek()\n7. exit\n8. size\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ele;
            int n;
            cout << "\nEnter the number of element: ";
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                cout << "\nEnter the element: ";
                cin >> ele;
                st.enqueue(ele);
            }
            break;
        }

        case 2:
        {
            st.dequeue();
            break;
        }

        case 3:
        {
            cout << "empty: " << st.isEmpty();
            break;
        }

        case 5:
        {
            st.print();
            break;
        }

        case 6:
        {
            cout << endl
                 << st.peek();
            break;
        }

        case 7:
        {
            x = false;
            break;
        }
        }
    }

    return 0;
}