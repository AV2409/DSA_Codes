#include <bits/stdc++.h>
using namespace std;
class player
{
    string name;

public:
    int score;
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
};

class team
{
    player players[3];
    int sum;

public:
    void set_player()
    {
        for (int i = 0; i < 3; i++)
        {
            string name;
            int score;
            cin >> name >> score;
            players[i].set_player(name, score);
        }
    }

    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            players[i].display();
            cout << endl;
        }
    }

    int add_score()
    {
        for (int i = 0; i < 3; i++)
        {
            sum += players[i].score;
        }
        return sum;
    }

    friend bool comp_score(team t1, team t2);
};

bool comp_score(team t1, team t2)
{
    if (t1.sum > t2.sum)
        return 1;
    else
        return 0;
}
int main()
{
    team t1;
    t1.set_player();
    t1.display();
    cout<<"score: "<<t1.add_score()<<endl;

    team t2;
    t2.set_player();
    t2.display();
    cout<<"score: "<<t2.add_score()<<endl;

    if (comp_score(t1,t2)){
        cout<<"team 1 won";
    }
    else{
        cout<<"team 2 won";
    }

        return 0;
}