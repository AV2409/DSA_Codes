// #include <iostream>
// using namespace std;
// #define N 9
// bool isSafe(int board[N][N], int row, int col, int num)
// {
//     for (int x = 0; x < N; x++)
//     {
//         if (board[row][x] == num || board[x][col] == num)
//             return false;
//     }

//     int startRow = row - row % 3, startCol = col - col % 3;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (board[i + startRow][j + startCol] == num)
//                 return false;
//         }
//     }

//     return true;
// }
// bool solveSudoku(int board[N][N])
// {
//     int row, col;
//     bool isEmpty = false;
//     for (row = 0; row < N; row++)
//     {
//         for (col = 0; col < N; col++)
//         {
//             if (board[row][col] == 0)
//             {
//                 isEmpty = true;
//                 break;
//             }
//         }
//         if (isEmpty)
//             break;
//     }
//     if (!isEmpty)
//         return true;

//     for (int num = 1; num <= 9; num++)
//     {
//         if (isSafe(board, row, col, num))
//         {
//             board[row][col] = num;

//             if (solveSudoku(board))
//                 return true;

//             board[row][col] = 0;
//         }
//     }
//     return false;
// }
// void printBoard(int board[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             cout << board[i][j] << " ";
//         cout << endl;
//     }
// }

// int main()
// {
//     int board[N][N] = {
//         {3, 0, 6, 5, 7, 8, 4, 0, 0},
//         {5, 2, 0, 0, 0, 0, 0, 0, 0},
//         {0, 8, 7, 0, 0, 0, 0, 3, 1},
//         {0, 0, 3, 0, 1, 0, 0, 8, 0},
//         {9, 0, 0, 8, 6, 3, 0, 0, 5},
//         {0, 5, 0, 0, 9, 0, 6, 0, 0},
//         {1, 3, 0, 0, 0, 0, 2, 5, 0},
//         {0, 0, 0, 0, 0, 0, 0, 7, 4},
//         {0, 0, 5, 2, 8, 6, 3, 0, 0}};

//     if (solveSudoku(board))
//     {
//         cout << "Solved Sudoku: " << endl;
//         printBoard(board);
//     }
//     else
//     {
//         cout << "No solution exists" << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define N 9

bool isSafe(int board[N][N], int row, int col, int num)
{
    for (int r = 0; r < N; r++)
    {
        if (board[r][col] == num)
            return false;
    }

    for (int c = 0; c < N; c++)
    {
        if (board[row][c] == num)
            return false;
    }

    int stRow = (row / 3) * 3;
    int stCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[stRow + i][stCol + j] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int board[N][N], int row, int col)
{
    int nextRow = row, nextCol = col + 1;
    if (nextCol == N)
    {
        nextRow++;
        nextCol = 0;
    }
    if (nextRow == N)
        return true;

    if (board[row][col] != 0)
        return solveSudoku(board, nextRow, nextCol);

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board, nextRow, nextCol))
                return true;

            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int board[N][N] = {
        {7, 3, 0, 9, 0, 0, 0, 1, 0},
        {6, 0, 1, 3, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 7, 5, 0, 0, 0, 0, 0, 0},
        {9, 1, 0, 0, 0, 3, 2, 0, 4},
        {0, 0, 0, 0, 0, 1, 0, 7, 0},
        {5, 2, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 0, 9}};

    if (solveSudoku(board, 0, 0))
    {
        cout << "Solved Sudoku: " << endl;
        printBoard(board);
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}