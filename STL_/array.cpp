#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 4> a = {1, 2, 3, 4};

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout<<endl<<"Element at index 2: "<<a.at(2);
    cout<<endl<<"Array is empty: "<<a.empty();
    cout<<endl<<"First element: "<<a.front();
    cout<<endl<<"last element: "<<a.back();

}