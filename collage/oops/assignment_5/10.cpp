#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    string address;

    Person(string s1 = "NAN", string s2 = "NAN")
    {
        name = s1;
        address = s2;
    }
};

class student : virtual public Person
{
public:
    int stuId;
    char grade;

    student(string s1, string s2, int id, char g) : Person(s1, s2)
    {
        stuId = id;
        grade = g;
    }
};

class teacher : virtual public Person
{
public:
    int empId;
    string department;

    teacher(string s1, string s2, int e_id, string dept) : Person(s1, s2)
    {
        empId = e_id;
        department = dept;
    }
};

class TA : public student, public teacher
{
public:
    TA(string s1, string s2, int id, int e_id, char g, string dept) : Person(s1, s2), student(s1, s1, id, g), teacher(s1, s2, e_id, dept)
    {
    }
};
int main()
{
    TA obj("John", "H-1,S-4", 101, 2001, 'A', "Math");
    cout << "Name: " << obj.name << endl;
    cout << "Address: " << obj.address << endl;
    cout << "Student ID: " << obj.stuId << endl;
    cout << "Grade: " << obj.grade << endl;
    cout << "Employee ID: " << obj.empId << endl;
    cout << "Department: " << obj.department << endl;

    return 0;
}