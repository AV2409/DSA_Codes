#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;      //LIFO--> Last in First out

    st.push(5);//{5}
    st.push(3);//{3,5}
    st.push(6);//{6,3,5}
    st.push(7);//{7,6,3,5}

    cout << endl << st.top();
    cout << endl << st.size();

    st.pop();

    cout << endl << st.top();
    cout << endl << st.size();

    cout << endl << st.empty();

    stack<int>st1,st2;

    st1.push(1);
    st2.push(3);
    st2.push(4);

    st1.swap(st2);

    cout << endl << st1.top();
    cout << endl << st2.top();


}