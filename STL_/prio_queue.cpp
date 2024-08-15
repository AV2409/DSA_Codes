#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> q;      //max heap

    q.push(5);//{5}
    q.push(3);//{5,3}
    q.push(6);//{5,3,6}
    q.push(7);//{5,3,6,7}

    cout << endl ;
    int n=q.size();
    for(int i=0;i<n;i++){
        cout<<q.top()<<" ";
        q.pop();
    }

    priority_queue<int,vector<int>,greater<int>> mini;      //max heap

    mini.push(5);//{5}
    mini.push(3);//{5,3}
    mini.push(6);//{5,3,6}
    mini.push(7);//{5,3,6,7}

    cout << endl ;
    int m=mini.size();
    for(int i=0;i<n;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }



    priority_queue<int>q1,q2;

    q1.push(1);
    q2.push(3);
    q2.push(4);

    q1.swap(q2);

    cout << endl << q1.top();
    cout << endl << q2.top();


}