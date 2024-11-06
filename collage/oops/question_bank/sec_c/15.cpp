#include <bits/stdc++.h>
using namespace std;

class investment
{
    int initial;
    int curr;
    int profit;
    float per_profit;

public:
    investment(int initial, int curr)
    {
        this->initial = initial;
        this->curr = curr;
        profit = this->curr - this->initial;
        per_profit = (float)profit / initial;
    }

    void display1()
    {
        cout << "\ninitial: " << initial;
        cout << "\ncurr: " << curr;
        cout << "\nprofit: " << profit;
        cout << "\nper_profit: " << per_profit;
    }
};

class house
{
    string street;
    int square_feet;

public:
    house(string street, int sq)
    {
        this->street = street;
        this->square_feet = sq;
    }

    void display2()
    {
        cout << "\nstreet: " << street;
        cout << "\nsquare_feet: " << square_feet;
    }
};

class HouseThatIsAnInvestment : public investment, public house
{
public:
    HouseThatIsAnInvestment(int initial, int curr, string street, int sq) : investment(initial, curr), house(street, sq)
    {
    }
    void display()
    {
        display1();
        display2();
    }
};

int main()
{
    HouseThatIsAnInvestment h1(100000, 120000, "Khanna", 300);
    h1.display();

        return 0;
}