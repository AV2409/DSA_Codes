// #include <iostream>
// #include <vector>
// using namespace std;
// bool isSafe(const vector<int> &queens, int row, int col)
// {
//     for (int r = 0; r < row; ++r)
//     {
//         int c = queens[r];
//         if (c == col || abs(c - col) == abs(r - row))
//             return false;
//     }
//     return true;
// }
// bool solve(int n, vector<int> &queens, int row, vector<int> &result)
// {
//     if (row == n)
//     {
//         for (int i = 0; i < n; ++i)
//             result.push_back(queens[i] + 1);
//         return true;
//     }
//     for (int col = 0; col < n; ++col)
//     {
//         if (isSafe(queens, row, col))
//         {
//             queens[row] = col;
//             if (solve(n, queens, row + 1, result))
//                 return true;
//         }
//     }
//     return false;
// }
// vector<int> solveNQueens(int n)
// {
//     vector<int> queens(n, -1);
//     vector<int> result;
//     solve(n, queens, 0, result);
//     return result;
// }

// int main()
// {
//     int n = 4;
//     vector<int> solution = solveNQueens(n);
//     for (int pos : solution)
//     {
//         cout << pos << " ";
//     }
//     cout << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> &queens, int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        int c = queens[r];
        if (c == col || abs(c - col) == abs(r - row))
            return false;
    }
    return true;
}

bool helper(vector<int> &queens, int n, int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
            cout << queens[i] + 1 << " ";
        cout << endl;
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(queens, k, col))
        {
            queens[k] = col;
            helper(queens, n, k + 1);
        }
    }
    return false;
}

void nQueen(int n)
{
    vector<int> queens(n, -1);
    helper(queens, n, 0);
}

int main()
{
    int n = 4;
    nQueen(n);
    return 0;
}