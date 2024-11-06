#include <bits/stdc++.h>
using namespace std;
class bank_manager;
class bank_account
{
protected:
    int balance;

public:
    int return_balance() const
    {
        return balance;
    }
};

class savings_account : public bank_account
{
protected:
    string saving_acc_no;
};

class current_account : public savings_account
{
protected:
    string acc_no;

    friend class bank_manager;
};

int main()
{

    return 0;
}