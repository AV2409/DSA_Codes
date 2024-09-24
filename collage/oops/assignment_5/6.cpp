#include <bits/stdc++.h>
using namespace std;

class book
{
protected:
    string title;
    string author;
    int price;

public:
    book(string title = "NAN", string author = "NAN", int price = 0)
    {
        cout<<endl<<"c1 called"<<endl;
        this->title = title;
        this->author = author;
        this->price = price;
    }
};

class textbook : public book
{
private:
    string subject;

public:
    textbook(string tit = "NAN", string auth = "NAN", int price = 0, string sub = "NAN") : book(tit, auth, price)
    {
        cout<<endl<<"c2 called"<<endl;
        this->subject = sub;
    }
    void insert_details(string tit, string auth, int price, string sub)
    {
        book(tit, auth, price);
        this->subject = sub;
    }

    void display()
    {
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Price: " << this->price << endl;
        cout << "Subject: " << this->subject << endl;
    }
};

int main()
{
    textbook t1("XYZ", "ABC", 500, "ENglish");

    textbook t2;
    t1.display();
    t2.display();

    return 0;
}