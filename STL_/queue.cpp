#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;      //FIFO--> First in First out

    q.push(5);//{5}
    q.push(3);//{5,3}
    q.push(6);//{5,3,6}
    q.push(7);//{5,3,6,7}

    cout << endl << q.front();
    cout << endl << q.size();


    q.pop();

    cout << endl << q.front();
    cout << endl << q.size();

    cout << endl << q.empty();

    queue<int>q1,q2;

    q1.push(1);
    q2.push(3);
    q2.push(4);

    q1.swap(q2);

    cout << endl << q1.front();
    cout << endl << q2.front();


}