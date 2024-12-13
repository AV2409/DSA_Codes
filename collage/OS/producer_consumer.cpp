#include <iostream>
using namespace std;

class Process
{
public:
    static int count;
    static const int bufferSize = 5;
    void producer()
    {
        if (count < bufferSize)
        {
            count++;
            cout << "Producer produced an item. Total items: " << count << endl;
        }
        else
        {
            cout << "Buffer is full. Producer cannot produce." << endl;
        }
    }
    void consumer()
    {
        if (count > 0)
        {
            cout << "Consumer consumed an item. Total items before consuming: " << count << endl;
            count--;
        }
        else
        {
            cout << "Buffer is empty. Consumer cannot consume." << endl;
        }
    }
};

int Process::count = 0;

int main()
{
    Process p;

    cout << "Producer starts producing: " << endl;
    for (int i = 0; i < 7; ++i)
    {
        p.producer();
    }
    cout << endl;

    cout << "Consumer starts consuming: " << endl;
    for (int i = 0; i < 7; ++i)
    {
        p.consumer();
    }

    return 0;
}
