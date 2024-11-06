#include <bits/stdc++.h>
using namespace std;

class transaction;
class account
{
private:
    double balance;

public:
    account(double val)
    {
        balance = val;
    }
    double get_balance()
    {
        return balance;
    }

    friend void trans(account &s, account &rs, transaction t);
};

class transaction
{
private:
    double amount;

public:
    transaction(double val)
    {
        amount = val;
    }

    friend void trans(account &s, account &rs, transaction t);
};

void trans(account &s, account &rs, transaction t)
{
    if (t.amount > s.balance)
    {
        cout << "Not sufficient balance";
        return;
    }

    s.balance = s.balance - t.amount;
    rs.balance = rs.balance + t.amount;
}

int main()
{
    account a1(1000);
    account a2(500);

    transaction t(2000);

    cout << "a1: " << a1.get_balance() << endl;
    cout << "a2: " << a2.get_balance() << endl;
    trans(a1, a2, t);
    cout << "a1: " << a1.get_balance() << endl;
    cout << "a2: " << a2.get_balance() << endl;
    return 0;
}