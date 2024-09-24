#include <bits/stdc++.h>
using namespace std;

class speedometer
{
protected:
    int speed;

public:
    void set_speed(int speed)
    {
        this->speed = speed;
    }
};

class fuelGuage
{
protected:
    int fuel;

public:
    void set_fuel(int fuel)
    {
        this->fuel = fuel;
    }
};

class thermometer
{
protected:
    int temprature;

public:
    void set_temprature(int temprature)
    {
        this->temprature = temprature;
    }
};

class carDashboard : public speedometer, public fuelGuage, public thermometer
{
public:
    void display()
    {
        cout << "speed: " << this->speed << endl;
        cout << "fuel: " << this->fuel << endl;
        cout << "temprature: " << this->temprature << endl;
    }
};

int main()
{
    carDashboard d1;

    d1.set_fuel(60);
    d1.set_speed(90);
    d1.set_temprature(100);
    d1.display();
    return 0;
}