#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char directions[4] = {'U', 'D', 'L', 'R'};
bool is_valid(int x, int y, int n, int m, vector<vector<bool>> &visited, const vector<string> &grid)
{
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && (grid[x][y] == '.' || grid[x][y] == 'B');
}
pair<bool, string> bfs_path(int start_x, int start_y, int end_x, int end_y, int n, int m, const vector<string> &grid)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> move_dir(n, vector<char>(m, ' '));
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (x == end_x && y == end_y)
        {
            string path;
            while (x != start_x || y != start_y)
            {
                path += move_dir[x][y];
                auto [px, py] = parent[x][y];
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            return {true, path};
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny, n, m, visited, grid))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                move_dir[nx][ny] = directions[i];
                q.push({nx, ny});
            }
        }
    }

    return {false, ""};
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    pair<int, int> start, end;
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
    auto [found, path] = bfs_path(start.first, start.second, end.first, end.second, n, m, grid);

    if (found)
    {
        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
