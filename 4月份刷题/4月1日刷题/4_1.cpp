#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int h = grid.size();
    int l = grid[0].size();
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                ++ans;
            }
        }
    }
    return ans;
}

// dfs深度优先
void dfs(vector<vector<char>> &grid, int r, int c)
{
    if (!isAera(grid, r, c))
        return;

    if (grid[r][c] == '0')
        return;
    if (grid[r][c] == '2')
        return;
    if (grid[r][c] == '1')
        grid[r][c] = '2';

    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);

    return;
}

// 判断是否合规网格
bool isAera(vector<vector<char>> &grid, int r, int c)
{
    return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
}

int orangesRotting(vector<vector<int>> &grid)
{
    int fresh = 0;
    queue<pair<int, int>> que;
    int h = grid.size();
    int l = grid[0].size();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (grid[i][j] == 1)
            {
                fresh++;
            }
            else if (grid[i][j] == 2)
            {
                que.push({i, j});
            }
        }
    }
    int round = 0;
    while (!que.empty() && fresh)
    {
        int size = que.size();
        round++;
        for (int i = 0; i < size; i++)
        {
            auto it = que.front();
            que.pop();

            int r = it.first;
            int c = it.second;
            if (r - 1 >= 0 && grid[r - 1][c] == 1)
            {
                grid[r - 1][c] = 2;
                que.push({r - 1, c});
                fresh--;
            }
            if (r + 1 < h && grid[r + 1][c] == 1)
            {
                grid[r + 1][c] = 2;
                que.push({r + 1, c});
                fresh--;
            }
            if (c - 1 >= 0 && grid[r][c - 1] == 1)
            {
                grid[r][c - 1] = 2;
                que.push({r, c - 1});
                fresh--;
            }
            if (c + 1 < l && grid[r][c + 1] == 1)
            {
                grid[r][c + 1] = 2;
                que.push({r, c + 1});
                fresh--;
            }
        }
    }
    if (fresh == 0)
        return round;
    return -1;
}

int main()
{
    return 0;
}