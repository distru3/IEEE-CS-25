#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int dfs(int x, int y, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
        return 0;
    int volume = grid[x][y];
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        volume += dfs(nx, ny, grid);
    }
    return volume;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int maxVolume = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > 0)
                {
                    maxVolume = max(maxVolume, dfs(i, j, grid));
                }
            }
        }
        cout << maxVolume << endl;
    }
    return 0;
}
