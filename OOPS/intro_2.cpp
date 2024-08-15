#include<iostream>
using namespace std;

class Hero
{
    private:
    char level;

    public:
    
    int health;

//default constructor
    Hero(){
        cout<<"Constructor Created"<<endl;
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

//Copy constructor

    Hero(Hero& temp)
    {
        this->health=temp.health;
        this->level=temp.level;
    }

    void print(){
        cout<<"Health: "<< health<<endl;
        cout<<"level: "<< level;
    }

    char getlevel(){
        return level;
    }

    void setlevel(char c){
        level=c;
    }
};

class test
{

};

int main()
{
/*
    Hero a;    //object bnadiya hero class kaa

    a.health=99;
    a.setlevel('B');
    
    cout<<"Health of a is: "<<a.health<<endl;
    cout<<"Level of a is: "<<a.getlevel()<<endl;

    Hero *b= new Hero;

//First way
    (*b).health=98;
    (*b).setlevel('A');

//Second way
    b->health=96;
    b->setlevel('D');

    cout<<"Health of b is: " << (*b).health<<endl;
    cout<<"Level of b is: " <<(*b).getlevel()<<endl;

    cout<<"Health of b is: " << b->health<<endl;
    cout<<"Level of b is: " <<b->getlevel()<<endl;
*/

/*
    // object created statically
    cout<<"Hi"<<endl;
    Hero ram;
    cout<<"Hello"<<endl<<endl;

    //dynamically
    cout<<"Hi"<<endl;
    Hero *x=new Hero;
    cout<<"Hello"<<endl<<endl;
*/


/*

//constructors
    Hero ram(22);
    cout<<"address: "<<&ram<<endl;

    Hero *x=new Hero(10);

    Hero y(99,'c');

    cout<<y.health<<" "<<y.getlevel();

*/

    Hero s(89,'D');

// copy constructor
    Hero r(s);

    r.print();
}