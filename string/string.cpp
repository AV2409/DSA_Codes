#include <bits/stdc++.h>
using namespace std;

int getlength(char c[]){
    int count=0;
    int i=0;
    while(c[i++]!='\0'){
        count++;
        // i++;
    }
    return count;
}
int main()
{
    char name[20];

    cout << "Enter the name: ";

    cin >> name;
    int i = 0;
    cout << endl;

    while (name[i] != '\0')
    {
        cout << name[i];
        i++;
    }

    cout<<endl<<"Length: "<<getlength(name);

    name[4] = '\0';
    cout << endl;

    cout << name;

    
}
