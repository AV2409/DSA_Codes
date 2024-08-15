#include<iostream>
using namespace std;

class Human {

    private:
    int height;

    public: 
    int weight;

    protected:
    int age;

    public:
    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;

    }

};

class Male: public Human {

    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        // return this->height;//not possible
        return 0;
    }

    int getage(){
        return age;
    }

};



int main() {

    Male m1;
    //cout << m1.height << endl;




    Male object1;
   // cout << object1.age << endl;//not possible
   cout << object1.getage() << endl;
    cout << object1.weight << endl;
    // cout << object1.height << endl;

    cout << object1.color << endl;

    object1.setWeight(84);
    cout << object1.weight << endl;
    object1.sleep();


    return 0;
}