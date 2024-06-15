#include <iostream>
using namespace std;

#define s 9
void print(int grid[s][s])
{
    for (int row = 0; row < s; row++)
    {
        for (int col = 0; col < s; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[s][s], int row, int col, int num)
{
   
    for (int x = 0; x < s; x++)
        if (grid[row][x] == num)
            return false;

    
    for (int x = 0; x < s; x++)
        if (grid[x][col] == num)
            return false;


    int startRow = row - row % 3, 
            startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}


bool solveSudoku(int grid[s][s], int row, int col)
{

    if (row == s - 1 && col == s)
        return true;

    if (col == s)
    {
        row++;
        col = 0;
    }


    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= s; num++)
    {
        
    
        if (isSafe(grid, row, col, num))
        {
           
            grid[row][col] = num;

            
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
       
        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    int grid[s][s] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0}, 
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0} };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "No solution exists";

    return 0;
}

