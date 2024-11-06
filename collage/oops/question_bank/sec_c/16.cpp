#include <bits/stdc++.h>
using namespace std;

class movie
{
private:
    string title;
    int year;
    string director;

public:
    void setTitle(string title);
    void setYear(int year);
    void setDirector(string director);

    void display()
    {
        cout << "\ntitle: " << title;
        cout << "\nyear: " << year;
        cout << "\ndirector: " << director;
    }
};

void movie::setTitle(string title)
{
    this->title = title;
}
void movie::setYear(int year)
{
    this->year = year;
}
void movie::setDirector(string director)
{
    this->director = director;
}

int main()
{
    movie m;
    m.setTitle("Mirzapur");
    m.setYear(2020);
    m.setDirector("xyz");
    m.display();
    return 0;
}