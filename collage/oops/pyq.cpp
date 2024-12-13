// #include <bits/stdc++.h>
// using namespace std;

// class shape
// {
// public:
//     double val1;
//     double val2;

//     void getData();
//     virtual void displayArea() = 0;
// };

// class rectangle : public shape
// {
// public:
//     void displayArea();
// };

// class triangle : public shape
// {
// public:
//     void displayArea();
// };

// void shape::getData()
// {
//     double x;
//     double y;
//     cin >> x >> y;
//     val1 = x;
//     val2 = y;
// }

// void rectangle::displayArea()
// {
//     cout << val1 * val2 << endl;
// }

// void triangle::displayArea()
// {
//     cout << 0.5 * val1 * val2 << endl;
// }

// int main()
// {
//     shape *ptr[2] = {new rectangle(), new triangle};
//     ptr[0]->getData();
//     ptr[1]->getData();

//     ptr[0]->displayArea();
//     ptr[1]->displayArea();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

template <class T>
class num
{
    T number;

public:
    void input()
    {
        T n;
        cin >> n;
        number = n;
    }
    void show()
    {
        cout << number << endl;
    }

    // num<T> operator+(num<T> &t)
    // {
    //     num<T> temp;
    //     temp.number = number + t.number;
    //     return temp;
    // }
    num<T> operator+(num<T> &t);
};

template <class T>
num<T> num<T>::operator+(num<T> &t)
{
    num<T> temp;
    temp.number = number + t.number;
    return temp;
}

int main()
{
    // num<int> n1;
    // num<int> n2;
    // n1.input();
    // n2.input();
    // num<int> n3 = n1 + n2;
    // n3.show();

    num<double> n1;
    num<double> n2;
    n1.input();
    n2.input();
    num<double> n3 = n1 + n2;
    n3.show();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Time
// {
//     int hr;
//     int min;

// public:
//     Time(int x = 0, int y = 0)
//     {
//         hr = x;
//         min = y;
//     }
//     void show()
//     {
//         cout << hr << " : " << min << endl;
//     }

//     friend bool operator==(Time t1, Time t2);
//     friend bool operator!=(Time t1, Time t2);
// };

// bool operator==(Time t1, Time t2)
// {
//     if (t1.hr == t2.hr && t1.min == t2.min)
//     {
//         return 1;
//     }
//     return 0;
// }
// bool operator!=(Time t1, Time t2)
// {
//     if (t1.hr == t2.hr && t1.min == t2.min)
//     {
//         return 0;
//     }
//     return 1;
// }

// int main()
// {
//     Time t1(10, 30);
//     Time t2(10, 30);
//     Time t3(10, 40);
//     Time t4(11, 30);
//     cout << "t1 == t2: " << (t1 == t2) << endl;
//     cout << "t1 == t3: " << (t1 == t3) << endl;
//     cout << "t1 == t4: " << (t1 == t4) << endl;

//     cout << "t1 != t2: " << (t1 != t2) << endl;
//     cout << "t1 != t3: " << (t1 != t3) << endl;
//     cout << "t1 != t4: " << (t1 != t4) << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Fahrenheit
// {

//     float f;

// public:
//     Fahrenheit()
//     {
//     }
//     Fahrenheit(float x)
//     {
//         f = x;
//     }
//     float get_f()
//     {
//         return f;
//     }
//     void set_f(float y)
//     {
//         f = y;
//     }

//     bool operator<(Fahrenheit far)
//     {
//         if (f < far.f)
//         {
//             return true;
//         }
//         return false;
//     }
// };

// class Celsius
// {
//     float c;

// public:
//     Celsius() {}
//     Celsius(float x)
//     {
//         c = x;
//     }
//     float get_c()
//     {
//         return c;
//     }
//     void set_c(float y)
//     {
//         c = y;
//     }

//     operator Fahrenheit()
//     {
//         float temp = (1.8 * c) + 32;
//         return Fahrenheit(temp);
//     }
// };
// int main()
// {
//     // Create objects
//     Fahrenheit f1(45), f2;
//     Celsius c1(34);

//     // Task 1: Convert Celsius to Fahrenheit using type casting operator
//     f2 = c1;
//     cout << f2.get_f();
//     // Task 2: Compare Fahrenheit objects using < operator
//     if (f1 < f2)
//     {
//         cout << "f1 is smaller than f2" << endl;
//     }
//     else
//     {
//         cout << "f1 is not smaller than f2" << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// void checkcgpa(int cgpa)
// {
//     if (cgpa >= 8)
//         throw "very good";
//     if (cgpa >= 6 && cgpa < 8)
//         throw 'h';
//     if (cgpa >= 4 && cgpa < 6)
//         throw 1.1;
//     if (cgpa < 4)
//         throw 1;
// }

// int main()
// {

//     try
//     {
//         // checkcgpa(9);
//         // checkcgpa(7);
//         checkcgpa(5);
//         checkcgpa(3);
//     }
//     catch (const char *s)
//     {
//         cout << s << endl;
//     }

//     catch (char s)
//     {
//         cout << s << endl;
//     }

//     catch (double s)
//     {
//         cout << s << endl;
//     }

//     catch (int s)
//     {
//         cout << s << endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// class st
// {
//     char n[100];

// public:
//     st(const char *x = "")
//     {
//         strcpy(n, x);
//     }
//     st operator+(st s1)
//     {
//         st temp;
//         strcpy(temp.n, n);
//         strcat(temp.n, " ");
//         strcat(temp.n, s1.n);
//         return temp;
//     }

//     void show()
//     {
//         cout << n << endl;
//     }
// };

// int main()
// {
//     st s1("Hello");
//     st s2("world");

//     st s3 = s1 + s2;

//     s3.show();
//     return 0;
// }