#include<iostream>
using namespace std;

class Hero
{
    private:
    int x;
    int y;

    public:
    char level;
    int health;

    int gety(){
        return y;
    }

    char getlevel(){
        return level;
    }

    void set_y(int n){
        y=n;
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
    Hero h1;    //object bnadiya hero class kaa
    test e;
    cout<<sizeof(h1)<<endl;
    cout<<sizeof(e)<<endl;
    // cout<<h1.x<<endl;  //cannot access as it is a private member
    h1.level='A';
    h1.health=77;
    cout<<h1.level<<endl;
    cout<<h1.health<<endl;

    //getters and setters


    h1.set_y(6);

    cout<<"y="<<h1.gety()<<endl;

    h1.setlevel('C');

    cout<<"level="<<h1.getlevel()<<endl;




}