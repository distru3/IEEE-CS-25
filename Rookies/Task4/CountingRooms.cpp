#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
bool is_valid(int x, int y, int n, int m, vector<vector<bool>> &visited, const vector<string> &grid)
{
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == '.';
}
void bfs(int start_x, int start_y, int n, int m, vector<vector<bool>> &visited, const vector<string> &grid)
{
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid(nx, ny, n, m, visited, grid))
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int room_count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                bfs(i, j, n, m, visited, grid);
                room_count++;
            }
        }
    }
    cout << room_count << endl;
    return 0;
}
