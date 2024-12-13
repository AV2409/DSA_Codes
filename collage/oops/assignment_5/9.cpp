#include <iostream>
using namespace std;

class Base
{
public:
    char make;
    string model;
    int year;

    Base(char m, string mm, int y)
    {
        make = m;
        model = mm;
        year = y;
    }
};
class Truck : public Base
{

public:
    int load;
    Truck(char m, string mm, int y, int l) : Base(m, mm, y)
    {
        load = l;
    }
};

class RTruck : public Truck
{
    char temp_control;

public:
    RTruck(char m, string mm, int y, int l, char t) : Truck(m, mm, y, l)
    {
        temp_control = t;
    }

    void display()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Load: " << load << endl;
        cout << "Temperature Control: " << temp_control << endl;
    }
};

int main()
{
    RTruck rt('a', "VXI", 2019, 1000, 'A');
    rt.display();
}