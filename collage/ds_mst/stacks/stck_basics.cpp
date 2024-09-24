#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Stack
{
    int top = -1;
    int arr[MAX];

public:
    void push(int n)
    {
        if (top == MAX - 1)
        {
            cout << endl
                 << "Overflow" << endl;
        }

        else
        {
            arr[++top] = n;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << endl
                 << "Underflow" << endl;
        }

        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
            return 0;
    }

    bool isFull()
    {
        if (top == MAX - 1)
        {
            return 1;
        }
        else
            return 0;
    }

    int peak()
    {
        if (top == -1)
        {
            cout << "empty";
            return -1;
        }
        return arr[top];
    }

    void print()
    {
        cout << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    bool x = true;
    while (x)
    {
        cout << "\n1. push()\n2. pop()\n3. isEmpty()\n4. isFull()\n5. display()\n6. peek()\n7. exit\n";

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
                st.push(ele);
            }
            break;
        }

        case 2:
        {
            st.pop();
            break;
        }

        case 3:
        {
            cout << "empty: " << st.isEmpty();
            break;
        }

        case 4:
        {
            cout << "full: " << st.isFull();
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
                 << st.peak();
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