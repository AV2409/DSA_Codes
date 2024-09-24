#include <bits/stdc++.h>
using namespace std;

class player
{
private:
    string name;
    int score;

public:
    void set_player(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    void display()
    {
        cout << "Name: " << this->name << endl;
        cout << "Score: " << this->score << endl;
    }

    int get_score()
    {
        return score;
    }
};

class team
{
private:
    player p[3];
    int sum = 0;

public:
    void set_player()
    {
        for (int i = 0; i < 3; i++)
        {
            string name;
            int score;
            cin >> name >> score;
            p[i].set_player(name, score);
        }
    }

    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            p[i].display();
        }
    }

    void total()
    {
        for (int i = 0; i < 3; i++)
        {
            sum += p[i].get_score();
        }
        cout << endl
             << sum;
    }

    friend bool compare(team &t1, team &t2);
};

bool compare(team &t1, team &t2)
{
    if (t1.sum > t2.sum)
        return 1;
    return 0;
}

int main()
{
    team india;
    india.set_player();
    india.display();
    india.total();

    team aus;
    aus.set_player();
    aus.display();
    aus.total();

    if (compare(india, aus))
        cout << endl
             << "India won";

    else
        cout << endl
             << "Australia Won";

    return 0;
}