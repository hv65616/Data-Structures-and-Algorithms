// GFG Question:- Rat In Maze 1
// Question URL:- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;
void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, vector<vector<int>> &vis, string move, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
    }
    string dir = "DLRU";
    for (int k = 0; k < 4; k++)
    {
        int nexti = i + di[k];
        int nextj = j + dj[k];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && vis[nexti][nextj] == 0 && maze[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, maze, n, ans, vis, move + dir[k], di, dj);
            vis[i][j] = 0;
        }
    }
}
vector<string> findout(vector<vector<int>> &maze, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (maze[0][0] == 1)
    {
        solve(0, 0, maze, n, ans, vis, "", di, dj);
    }
    return ans;
}
int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = maze.size();
    vector<string> ans = findout(maze, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}