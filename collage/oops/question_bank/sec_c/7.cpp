#include <bits/stdc++.h>
using namespace std;

class fc;
class person
{
protected:
    string name;

public:
    person()
    {
    }
    person(string n)
    {
        name = n;
    }

    person(person &p)
    {
        cout << "\nperson called";
        name = p.name;
    }
};

class student : public person
{
protected:
    int id;

public:
    student()
    {
    }
    student(int n, string s) : person(s)
    {
        id = n;
    }

    student(student &s) : person(s)
    {
        cout << "\nstudent called";
        id = s.id;
    }
};

class graduate : public student
{
protected:
    string degree;

public:
    graduate(int n, string s, string deg) : student(n, s)
    {
        degree = deg;
    }

    graduate(graduate &g) : student(g)
    {
        cout << "\ngraduate called";
        degree = g.degree;
    }

    void display()
    {
        cout << id << " - " << name << " - " << degree;
    }

    friend class fc;
};

int main()
{
    graduate g1(56, "abc", "be");
    g1.display();

    graduate g2(g1);
    g2.display();

    return 0;
}