#include <bits/stdc++.h>
using namespace std;

void pattern9(int n)
{
    int i, j, k;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (k = 0; k < 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (k = 1; k <= 2 * n - 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n)

{
    int i, j;

    for (i = 0; i <= 2 * n - 1; i++)
    {
        if (i > n)
        {
            for (j = 0; j < 2 * n - i; j++)
            {
                cout << "* ";
            }
        }

        else
        {
            for (j = 0; j < i; j++)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void pattern11(int n)
{
    int i, j, start;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;

        for (j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern12(int n)
{
    int i, j, spaces;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        spaces = 2 * n - 2 * i;
        for (j = 1; j <= spaces; j++)
        {
            cout << "  ";
        }

        for (j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern13(int n)
{
    int i, j;
    int count = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void pattern14(int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void pattern15(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (j = 1; j <= n - i + 1; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void pattern16(int n)
{
    int i, j;
    char ch = 'A';
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= i; j++)
        {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}

void pattern17(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (j = 1; j <= 2 * i - 1; j++)
        {

            cout << ch;
            if (j < breakpoint)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }

        cout << endl;
    }
}

void pattern18(int n)

{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        char ch = 'A';
        int num = n - i + 1;
        ;
        ch = ch + (n - 1);
        for (j = 1; j <= i; j++)
        {

            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}

void pattern19(int n)
{
    int i, j;
    int isp = 0;
    for (i = 1; i <= n; i++)
    {

        // stars
        for (j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        // spaces
        for (j = 1; j <= isp; j++)
        {
            cout << "  ";
        }

        // stars

        for (j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
        isp+=2;
    }


    for (i = 1; i <= n; i++)
    {

        // stars
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // spaces
        for (j = 1; j <= 2 * n - 2 * i; j++)
        {
            cout << "  ";
        }

        // stars

        for (j = 1; j <= i; j++)
        {
            cout << "* ";
            ;
        }
        cout << endl;
    }
}

void pattern20(int n){
    int i,j;
    int stars=1;
    int star=1;
    int nsp=2*n-2;
    for(i=1;i<=2*n-1;i++){
        int breakpt=(2*n-1)/2;

        //stars
        
        for(j=1;j<=stars;j++){
            cout<<"* ";
            
        }
        if(i>breakpt) stars--;
        else stars++;

        
        //spaces
        for(j=1;j<=nsp;j++){
            cout<<"  ";
        }
        if(i>breakpt) nsp+=2;
        else nsp-=2;

        //stars
        for(j=1;j<=star;j++){
            cout<<"* ";
            
        }
        if(i>breakpt) star--;
        else star++;
        cout<<endl;
    }
}

void pattern21(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==1||i==n||j==1||j==n){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}

void pattern22(int n){
    int i,j;
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            int top,bottom,left,right;
            top=i;
            left=j;
            bottom=2*n-2-i;
            right=2*n-2-j;
            cout<<n-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}

int main()
{
    pattern22(4);
}