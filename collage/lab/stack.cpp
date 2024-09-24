#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;

class Stack
{
private:
    int arr[MAX];
    int top = -1;

public:
    void push(int n)
    {
        top++;
        // if(front==-1){
        //     front=0;
        //     arr[front]=n;
        // }
        // else{
        //     front++;
        //     arr[front]=n;
        // }
        arr[top] = n;
    }

    void pop()
    {
        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    bool isFull()
    {
        if (top == MAX - 1)
            return 1;
        return 0;
    }

    void display()
    {
        int x = top;
        while (x > -1)
        {
            cout << arr[x--] << " ";
        }
    }

    int peak()
    {
        return arr[top];
    }
};

string string_reversal(string str)
{
    Stack s1;

    int len = str.length();
    char strr[len];
    for (int i = 0; i < len; i++)
    {
        s1.push(str[i]);
    }

    int i = 0;
    while (i < len)
    {
        strr[i] = (char)s1.peak();
        s1.pop();
        i++;
    }
    return strr;
}

int main()
{
    Stack s;

    bool x = true;

    while (x)
    {
        int choice;
        cout << "1. Push\n2. POP\n3. isEmpty\n4. isFull\n5. display\n6. Peak\n7. Exit\n\n";
        cout << "Enter the choice: ";
        cin >> choice;
        cout << endl;
        string s5;
        string rev_st;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "enter the number: ";
            cin >> n;
            s.push(n);
            cout << endl;
            break;
        }

        case 2:
        {
            s.pop();
            cout << endl;
            break;
        }

        case 3:

        {
            cout << "Empty: " << s.isEmpty();
            cout << endl;
            break;
        }

        case 4:

        {
            cout << "Full: " << s.isFull();
            cout << endl;
            break;
        }

        case 5:

        {
            s.display();
            cout << endl;
            break;
        }
        case 6:

        {
            cout << s.peak();
            cout << endl;
            break;
        }
        case 7:

            cin >> s5;
            rev_st = string_reversal(s5);
            cout << rev_st;
            break;

        case 8:

            x = false;
            cout << endl;
            break;
        }
    }

        return 0;
}