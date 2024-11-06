#include <bits/stdc++.h>
using namespace std;
class person
{
protected:
    string name;

public:
    person(string name = "NAN")
    {
        cout << "\nperson";
        this->name = name;
    }
};

class address
{
private:
    string city;
    string zipcode;

public:
    address(string city = "NAN", string zipcode = "NAN")
    {
        cout << "\naddress";
        this->city = city;
        this->zipcode = zipcode;
    }

    string get_city()
    {
        return city;
    }

    string get_zipcode()
    {
        return zipcode;
    }
};

class employee : public person, public address
{
private:
    int id;

public:
    employee()
    {
        cout << "\nemp";
    }
    employee(int id, string name, string city, string zipcode) : person(name), address(city, zipcode)
    {
        this->id = id;
        cout << "\nemp";
    }

    int get_id()
    {
        return id;
    }

    string get_name()
    {
        return name;
    }
};

class company
{
private:
    string c_name1;
    double revenue1;
    employee e1;

public:
    company(string c_name, double revenue, employee e) : c_name1(c_name), revenue1(revenue), e1(e)
    {
        cout << "\ncompany";
    }

    void printDetails()
    {
        cout << "Company Name: " << c_name1 << endl;
        cout << "Revenue: $" << revenue1 << endl;
        cout << "Employee Name: " << e1.get_name() << endl;
        cout << "City: " << e1.get_city() << endl;
        cout << "Zip Code: " << e1.get_zipcode() << endl;
        cout << "Employee ID: " << e1.get_id() << endl;
    }
};

int main()
{
    employee e1(101, "abc", "xyz", "141401");

    company c1("pqr", 1000000, e1);
    c1.printDetails();
    return 0;
}