// C++ program to evaluate value of a postfix expression
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
private:
    float arr[MAX];
    int top = -1;

public:
    void push(float n)
    {
        top++;
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

    float peak()
    {
        return arr[top];
    }
};

float evaluatePostfix(string exp)
{

    Stack st;

    for (int i = 0; i < exp.size(); ++i)
    {

        if (isdigit(exp[i]))
            st.push(exp[i] - '0');

        else
        {
            float val1 = st.peak();
            st.pop();
            float val2 = st.peak();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.peak();
}

int main()
{
    string exp = "238/2*+31-5*-515*3/-";

    cout << "postfix evaluation: " << evaluatePostfix(exp);
    return 0;
}
