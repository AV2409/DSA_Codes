#include <bits/stdc++.h>
using namespace std;

void printRowSum(int arr[][4], int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        cout << endl
             << sum;
    }
}

void printColSum(int arr[][4], int m, int n)
{

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[j][i];
        }
        cout << endl
             << sum;
    }
}

int maxRowSum(int arr[][4], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        
        int temp=0;
        for (int j = 0; j < n; j++)
        {
            temp += arr[i][j];
            sum=max(sum,temp);
            
        }
        
    }
    return sum;
}

int main()
{
    
    int arr[3][4];
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << "\t";
        }
        cout << endl;
    }

    printRowSum(arr, 3, 4);
    cout<<endl;
    printColSum(arr,3,4);
    cout<<endl;
    cout<<endl;
    cout<<maxRowSum(arr,3,4);

    return 0;
}