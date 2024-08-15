#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    int health;

public:
    char level;
    char *name = new char[100];

    // default constructor
    Hero()
    {
        cout << "Default Constructor Created" << endl;
    }

    // Parameterised constructor

    Hero(int health)
    {
        // cout<<"This: "<<this<<endl;
        this->health = health;
    }

    Hero(int health, char level)
    {
        // cout<<"This: "<<this<<endl;
        this->health = health;
        this->level = level;
    }

    // Copy constructor

    // Hero(Hero& temp)
    // {
    //     char*ch=new char[strlen(temp.name)+1];

    //     strcpy(ch,temp.name);

    //     this->name=ch;
    //     this->health=temp.health;
    //     this->level=temp.level;
    // }
    
    Hero(Hero* temp)
    {
        this->name=temp->name;
        this->health=temp->health;
        this->level=temp->level;
    }

    void print()
    {
        cout << endl
             << "[ " << "Name: " << this->name << "   ";
        cout << "Health: " << this->health << "   ";
        cout << "level: " << this->level << "  ]" << endl;
    }

    char getlevel()
    {
        return level;
    }

    void setlevel(char c)
    {
        level = c;
    }

    int gethealth()
    {
        return health;
    }

    void sethealth(int n)
    {
        health = n;
    }

    void setname(char name[])
    {
        strcpy(this->name, name);
    }

    // ~Hero() {
    //     delete[] name;
    // }
};

int main()
{
    Hero h1(12, 'D');

    char name[9] = "Akshansh";

    h1.setname(name);

    cout << "h1: ";
    h1.print();

    // default copy constructor

    Hero h2(h1);
    // h2.print();
    // Hero h2=h1;

    h1.name[0] = 'a';
    h1.sethealth(15);
    h1.setlevel('A');
    cout << "h1: ";
    h1.print();

    cout << "h2: ";
    h2.print();

    // copy assignment operator
    h1 = h2;

    h1.name[0] = 'A';
    h1.sethealth(15);

    cout << "h1: ";
    h1.print();

    cout << "h2: ";
    h2.print();

    return 0;
}