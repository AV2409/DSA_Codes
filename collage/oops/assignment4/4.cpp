#include <bits/stdc++.h>
using namespace std;

class demo
{
private:
    // int a;

public:

    int a;
    demo(int a)
    {
        this->a = a;
    }

    void display()
    {
        cout << this->a;
    }

    ~demo()
    {
        cout << "bye" << " ";
    }
};

int main()
{
    
    demo *d2 = new demo(10);
    cout << endl;
    d2->display();
    cout<<endl;
    delete d2;
    
    demo *objArray = new demo[3] { demo(1), demo(2), demo(3) };
    
    // Access data members
    for (int i = 0; i < 3; i++) {
        cout << "Object " << i + 1 << " data: " << objArray[i].a << endl;
    }
    
    // Free the allocated memory
    delete[] objArray;
    return 0;
}