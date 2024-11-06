#include <bits/stdc++.h>
using namespace std;
class DB;
class DM
{
private:
    float m;
    float cm;

public:
    DM(float m = 0, float cm = 0)
    {
        this->m = m;
        this->cm = cm;
    }

    friend void addition(DM d1, DB d2, char ch);
};

class DB
{
private:
    float inch;
    float feet;

public:
    DB(float feet = 0, float inch = 0)
    {
        this->inch = inch;
        this->feet = feet;
    }

    friend void addition(DM d1, DB d2, char ch);
};

void addition(DM d1, DB d2, char ch)
{
    if (ch == 'm')
    {
        DM add;

        // Convert DB (feet and inches) to centimeters
        float total_cm_from_db = d2.feet * 12 * 2.54 + d2.inch * 2.54;
        cout << total_cm_from_db << endl;
        // Convert DM (meters and centimeters) to total centimeters
        float total_cm_from_dm = d1.m * 100 + d1.cm;
        cout << total_cm_from_dm << endl;
        // Total centimeters
        float total = total_cm_from_dm + total_cm_from_db;
        cout << total << endl;
        // Convert total centimeters back to meters and centimeters
        int meters = (int)(total / 100);          // Get meters
        float centimeters = total - meters * 100; // Remaining centimeters
        add.m = (int)(total / 100);
        add.cm = total - add.m * 100;

        cout << endl
             << add.m << "m " << add.cm << "cm";
    }

    else if (ch == 'i')
    {
        DB add;

        float cm = (d1.m * 100 + d1.cm) / 2.54;
        float in = d2.feet * 12 + d2.inch;

        float total = cm + in;
        add.feet = (int)(total / 12);
        add.inch = total - add.feet * 12;

        cout << endl
             << add.feet << "feet& " << add.inch << "inch";
    }
}

int main()
{
    cout << "enter the units: ";
    char ch;
    cin >> ch;

    DM m(5, 4);
    DB n(2, 3);

    addition(m, n, ch);
}