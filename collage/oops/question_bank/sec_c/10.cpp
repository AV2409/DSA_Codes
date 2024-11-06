#include <bits/stdc++.h>
using namespace std;

class shape
{
protected:
    const float area;

public:
    shape() : area(0.0) {}
    virtual float calculate_area() const = 0;
};

class circle : public shape
{
private:
    int r;

public:
    static int count;
    circle(int r)
    {
        count++;
        this->r = r;
    }
    float calculate_area() const
    {
        return 3.14 * r * r;
    }
};

int circle::count = 0;

int main()
{
    circle c1(5);
    cout << c1.calculate_area();

    circle c2(6);
    cout << c2.calculate_area();

    circle c3(7);
    cout << c3.calculate_area();

    cout << endl
         << "total" << circle::count;
    return 0;
}