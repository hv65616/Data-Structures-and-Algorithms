// Leetcode Question :- Sudoku Solver
// URL :- https://leetcode.com/problems/sudoku-solver/
#include <bits/stdc++.h>
using namespace std;
void solvesudoku(vector<vector<char>> &vt)
{
    solve(vt);
}
bool solve(vector<vector<char>> &vt)
{
    for (int i = 0; i < vt.size(); i++)
    {
        for (int j = 0; j < vt[0].size(); j++)
        {
            if (vt[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isvalid(vt, ch, i, j))
                    {
                        vt[i][j] = ch;
                        if (solve(vt) == true)
                        {
                            return true;
                        }
                        else
                        {
                            vt[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isvalid(vector<vector<char>> &vt, char ch, int r, int c)
{
    for (int i = 0; i < vt.size(); i++)
    {
        if (vt[i][c] == ch)
        {
            return false;
        }
        if (vt[r][i] == ch)
        {
            return false;
        }
        if (vt[3 * (r / 3) + (i / 3)][3 * (c / 3) + (i % 3)] == ch)
        {
            return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}