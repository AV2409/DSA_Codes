#include <bits/stdc++.h>
using namespace std;
class order
{
private:
    int id;
    static int count;

public:
    order()
    {
        count++;
        id = 100 + count;
    }

    static int total()
    {
        return count;
    }

    int get_id()
    {
        return id;
    }
};

int order::count = 0;
int main()
{
    cout << order::total() << endl;
    order o1;
    cout << "id: " << o1.get_id() << "\tcount: " << order::total() << endl;

    order o2;
    cout << "id: " << o2.get_id() << "\tcount: " << order::total() << endl;

    order o3;
    cout << "id: " << o3.get_id() << "\tcount: " << order::total() << endl;
    return 0;
}