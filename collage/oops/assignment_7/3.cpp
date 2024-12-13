#include <iostream>
using namespace std;
class Distance
{
private:
    int feet;
    int inch;

public:
    // Constructor
    Distance(int f = 0, int i = 0) : feet(f), inch(i) {}

    // Overload unary minus (-) operator
    // Distance operator-()
    // {
    //     feet = -feet;
    //     inch = -inch;

    //     return Distance(feet, inch);
    // }

    // Function to display the value

    friend void operator-(Distance &d1);
    void display() const
    {
        cout << feet << " feet,  " << inch << " inches" << endl;
    }
};

void operator-(Distance &d1)
{
    d1.feet = -d1.feet;
    d1.inch = -d1.inch;
}

int main()
{
    Distance num(10, 5);
    cout << "Original ";
    num.display();

    -num; // Using the overloaded unary minus
    cout << "Negated ";
    num.display();

    return 0;
}