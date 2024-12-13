// 1. basic to class--> constructors
// 2. class to basics--> type casting
// 3. class to class--> constructor or type conversion

#include <bits/stdc++.h>
using namespace std;
class square;
class rectangle
{
    int l;
    int b;

public:
    rectangle(int x = 0, int y = 0)
    {
        l = x;
        b = y;
    }
    // 1
    //  rectangle(square s1)
    //  {
    //      l = s1.getSide();
    //      b = s1.getSide();
    //  }

    void show()
    {
        cout << "l = " << l << ",b = " << b << endl;
    }
};
class square
{
    int s;

public:
    square(int x = 0)
    {
        s = x;
    }

    void show()
    {
        cout << "s = " << s << endl;
    }
    // 1
    //  int getSide()
    //  {
    //      return s;
    //  }

    // 2
    operator rectangle()
    {
        rectangle r1(s, s);
        return r1;
    }
};

int main()
{
    rectangle r1;
    r1.show();
    square s1(5);
    s1.show();

    rectangle r2 = s1;
    r2.show();

    return 0;
}