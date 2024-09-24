#include <bits/stdc++.h>
using namespace std;
class LibraryUser
{
protected:
    string name;
    int id;
    string mob;
};

class student : public LibraryUser
{
private:
    char grade;

public:
    void insert_details(int id, string name, string mob, char grade)
    {
        this->id = id;
        this->name = name;
        this->mob = mob;
        this->grade = grade;
    }

    void display()
    {
        cout << "id: " << this->id << endl;
        cout << "name: " << this->name << endl;
        cout << "mob: " << this->mob << endl;
        cout << "grade: " << this->grade << endl;
    }
};

class teacher : public LibraryUser
{
private:
    string department;

public:
    void insert_details(int id, string name, string mob, string department)
    {
        this->id = id;
        this->name = name;
        this->mob = mob;
        this->department = department;
    }

    void display()
    {
        cout << "id: " << this->id << endl;
        cout << "name: " << this->name << endl;
        cout << "mob: " << this->mob << endl;
        cout << "department: " << this->department << endl;
    }
};
int main()
{
    teacher t1;
    student s1;

    t1.insert_details(1001, "ABC", "1234567890", "COE");

    s1.insert_details(102, "XYZ", "1234567890", 'A');

    cout << "student: " << endl;
    s1.display();

    cout << "teacher: " << endl;
    t1.display();

    return 0;
}