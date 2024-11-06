#include <iostream> // Corrected header

using namespace std;

class STATIC
{
    static int x; // Static data member
    int y = 0;    // Non-static data member

public:
    // Function to increment static and non-static members
    void INCREMENT()
    {
        x++; // Increment static member
        y++; // Increment non-static member
    }

    // Static method to print the static member value
    static void PRINT()
    {
        cout << "The value of static data member: " << x << endl;
    }

    // Non-static method to display both static and non-static members
    void DISPLAY()
    {
        cout << "The value of static data member: " << x << endl;
        cout << "The value of Non-static data member: " << y << endl;
    }
};

// Initialize the static member
int STATIC::x = 0;

int main()
{
    STATIC s1, s2;

    // Display initial values for s1
    s1.DISPLAY();

    s2.DISPLAY();

    // Increment values for s1
    s1.INCREMENT();

    // Display values for s1 after increment
    s1.DISPLAY();

    // Display values for s2 (should show same static member but different non-static member)
    s2.DISPLAY();

    // Static method call to display static member value
    STATIC::PRINT();

    return 0;
}
