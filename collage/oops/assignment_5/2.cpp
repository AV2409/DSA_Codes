#include <bits/stdc++.h>
using namespace std;

class parent
{
    int a;

protected:
    int a1;

public:
    parent()
    {
        a = 10;
        cout << "parent constructor" << endl;
    }
    void display()
    {
        cout << a << endl;
    }
    ~parent()
    {
        a = 10;
        cout << "parent destructor" << endl;
    }
};

class child : public parent
{
    int b;

public:
    child()
    {
        b = 5;
        cout << "child constructor" << endl;
    }
    void print()
    {
        cout << b << endl;
    }
    
    void set_a1(int x){
        a1=x;
    }
    
    int get_a1(){
       return a1; 
    }
    ~child()
    {
        b = 5;
        cout << "child destructorr" << endl;
    }
};

int main()
{
    child ch;
    ch.display();
    ch.print();

    ch.set_a1(11);
    cout<<"a1="<<ch.get_a1()<<endl;
    return 0;
}