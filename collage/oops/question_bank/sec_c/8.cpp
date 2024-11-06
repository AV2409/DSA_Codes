#include <bits/stdc++.h>
using namespace std;
class bank_manager;
class bank_account
{
protected:
    int balance;

public:
    bank_account()
    {
    }

    bank_account(int bal)
    {
        balance = bal;
    }
    int return_balance() const
    {
        return balance;
    }
};

class savings_account : public bank_account
{
protected:
    string name;

public:
    savings_account()
    {
    }
    savings_account(int bal, string name) : bank_account(bal)
    {
        this->name = name;
    }
};

class current_account : public savings_account
{
protected:
    string acc_no;
    current_account()
    {
    }
    current_account(int bal, string name, string acc) : savings_account(bal, name)
    {
        acc_no = acc;
    }
    friend class bank_manager;
};

int main()
{

    return 0;
}