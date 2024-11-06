#include <bits/stdc++.h>
using namespace std;
class config
{
    string lang;
    static int count;
    static string def_lang;

public:
    config()
    {
        count++;
        lang = def_lang;

        if (count > 0)
        {
            cout << "\nno input your default language is set as " << lang;
        }
    }

    config(string ll)
    {
        count++;
        lang = ll;
        cout << "\nyour language is set as " << lang;
    }

    config(config &cc)
    {
        count++;
        lang = cc.lang;
        cout << "\nyour default language is set as " << lang;
    }

    static void display()
    {
        cout << "\nTotal players->" << count;
    }
};

int config::count = -1;
string config::def_lang = "english";

int main()
{
    static config for_def;
    config player1;
    config player2("Punjabi");
    config player3(for_def);

    config::display();

    return 0;
}