#include <bits/stdc++.h>
using namespace std;

class employee
{
    int id;
    string name;
    int salary;

public:
    employee(int id, string name, int salary)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void display_single()
    {
        cout << "\nid: " << id;
        cout << "\nName: " << name;
        cout << "\nsalary: " << salary;
    }

    void display(employee e[])
    {
        for (int i = 0; i < 5; i++)
        {
            if (e[i].salary > 1000)
            {
                e[i].display_single();
            }
        }
    }
};

int main()
{
    employee e[5] = {employee(101, "abc", 1000),
                     employee(102, "dbc", 1001),
                     employee(103, "ebc", 100),
                     employee(104, "fbc", 1001),
                     employee(105, "gbc", 1020)};

    e[0].display(e);
    return 0;
}