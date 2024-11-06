#include <iostream>
using namespace std;
class Distance
{
private:
    int feet;
    int inch;

public:
    // Constructor
    Distance(int f, int i) : feet(f), inch(i) {}

    // Overload unary minus (-) operator
    Distance operator-()
    {
        return Distance(-feet, -inch);
    }

    // Function to display the value
    void display() const
    {
        cout << feet << " feet,  " << inch << " inches" << endl;
    }
};

int main()
{
    Distance num(10, 5);
    cout << "Original ";
    num.display();

    Distance negNum = -num; // Using the overloaded unary minus
    cout << "Negated ";
    negNum.display();

    return 0;
}