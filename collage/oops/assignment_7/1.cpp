#include <iostream>
using namespace std;
class Counter
{
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter &operator++()
    {
        ++value;
        return *this;
    }

    Counter operator++(int)
    {
        Counter temp = *this;
        ++value;
        return temp;
    }

    void display() const
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Counter c(5);

    ++c;
    c.display();
    c++;
    c.display();

    return 0;
}