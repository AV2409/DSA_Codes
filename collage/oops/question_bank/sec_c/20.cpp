#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    int roll;
    string name;
    int marks[5];

public:
    student(int roll, string name, int arr[])
    {
        this->roll = roll;
        this->name = name;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = arr[i];
        }
    }

    void display()
    {
        cout << "\nname :" << name;
        cout << "\nroll :" << roll;

        cout << endl
             << "Marks: ";

        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << "\t";
        }
    }

    void calculate(student s[])
    {
        float sum[5] = {0};
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                sum[i] += s[j].marks[i];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            cout << sum[i] / 5 << "\t";
        }
    }
};

int main()
{
    int arr1[5] = {9, 10, 9, 9, 10};
    int arr2[5] = {9, 8, 2, 8, 10};
    int arr3[5] = {9, 6, 9, 9, 10};
    int arr4[5] = {9, 5, 3, 5, 10};
    int arr5[5] = {9, 1, 9, 7, 10};

    student s[5] = {student(101, "abc", arr1),
                    student(102, "abc", arr2),
                    student(103, "abc", arr3),
                    student(104, "abc", arr4),
                    student(105, "abc", arr5)};

    s[0].calculate(s);

    return 0;
}