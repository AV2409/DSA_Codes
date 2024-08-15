#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    int i, j;



    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout<<endl;
    // }

//    for(i=0;i<n;i++){
//     for(j=0;j<=i;j++){
//         cout<< "* ";
//     }
//     cout<<endl;
//    }


    // for (i=1;i<=n;i++){
    //     for(j=1;j<=i;j++){
    //         cout<< j<<" ";
    //     }

    //     cout<< endl;
    // }

    // for (i=1;i<=n;i++){
    //     for(j=1;j<=i;j++){
    //         cout<< i<<" ";
    //     }

    //     cout<< endl;
    // }

    // for(i=0;i<n;i++){
    //     for(j=0;j<n-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    pattern(n);
}