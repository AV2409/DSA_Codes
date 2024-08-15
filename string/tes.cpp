#include<iostream>
using namespace std;
void sortt(string &st){
    for (int i = 0; i < st.length() - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < st.length() - i - 1; j++)
        {
            if (st[j] > st[j + 1])
            {
                swap(st[j], st[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}



int main(){

    string st;

    st="car";

    cout<<endl<<st.length();
    cout<<endl<<st.size();

sortt(st);
    cout<<st;

}