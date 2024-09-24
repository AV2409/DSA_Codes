#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

class Stack
{
private:
    char arr[MAX];
    int top = -1;

public:
    void push(char n)
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

int main()
{
    Stack s;

    string str = "a+(b-c)";

    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            s.pop();
        }
    }

    s.display();
    if (s.isEmpty())
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Unbalanced";
    }
    return 0;
}