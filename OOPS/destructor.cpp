#include<bits/stdc++.h>
using namespace std;

class Hero
{
    private:
    int health;

    public:
    
    char level;
    char* name=new char[100];

//default constructor
    Hero(){
        cout<<"Default Constructor Created"<<endl;
        
    }

//Parameterised constructor

    Hero(int health)
    {
        // cout<<"This: "<<this<<endl;
        this->health=health;
    }

    Hero(int health,char level)
    {
        // cout<<"This: "<<this<<endl;
        this->health=health;
        this->level=level;
    }

// Copy constructor

    Hero(Hero& temp)
    {
        char*ch=new char[strlen(temp.name)+1];

        strcpy(ch,temp.name);

        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;
    }



    void print(){
        cout<<endl<< "[ "<< "Name: "<<this->name<<"   ";
        cout<<"Health: "<< this->health<<"   ";
        cout<<"level: "<< this->level<<"  ]"<<endl;
    }

    char getlevel(){
        return level;
    }

    void setlevel(char c){
        level=c;
    }

    int gethealth(){
        return health;
    }

    void sethealth(int n){
        health=n;
    }

    void setname(char name[]){
        strcpy(this->name,name);
    }

    ~Hero() {
        
        cout<<"Destructor called"<<endl;
    }
};


int main()
{
    //static;
    Hero a;

    //dynamic

    Hero* b=new Hero;

    delete b;
    

}