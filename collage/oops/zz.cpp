#include <bits/stdc++.h>
using namespace std;

class book
{

public:
    int price;
    int stock;
    string author;
    string title;
    string publisher;
    book(string auth, string t, string pub, int p, int s)
    {
        author = auth;
        title = t;
        publisher = pub;
        price = p;
        stock = s;
    }
    book()
    {
    }
};

bool check(string t, string auth, book *list, int &stock, int &price)
{
    for (int i = 0; i < 3; i++)
    {
        if ((list[i].title == t) && (list[i].author == auth))
        {
            stock = list[i].stock;
            price = list[i].price;
            return 1;
        }
    }
    return 0;
}
int main()
{
    book *list = new book[3]{book("abcd", "xyz", "harsh", 500, 10),
                             book("dcba", "xz", "harshc", 1999, 15),
                             book("abcdef", "yz", "harshl", 200, 19)};
    string t;
    string auth;

    cin >> t;
    cin >> auth;
    int stock;
    int price;
    if (check(t, auth, list, stock, price))
    {
        cout << "stock availaible\n";
        cout << "Enter the quantity";
        int q;
        cin >> q;

        if (q <= stock)
        {
            cout << "total cost=" << q * price;
            cout << "\n";
        }
        else
        {
            cout << "Less quantity availaible";
        }
    }

    else
    {
        cout << "not availaible";
    }

    return 0;
}