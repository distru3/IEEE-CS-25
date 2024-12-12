#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const vector<pair<int, int>> knight_moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
bool is_valid(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
int min_knight_moves(pair<int, int> start, pair<int, int> destination)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    q.push(start);
    visited[start.first][start.second] = true;
    int moves = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto current = q.front();
            q.pop();
            if (current == destination)
            {
                return moves;
            }
            for (const auto &move : knight_moves)
            {
                int new_x = current.first + move.first;
                int new_y = current.second + move.second;
                if (is_valid(new_x, new_y) && !visited[new_x][new_y])
                {
                    visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }
        ++moves;
    }
    return -1;
}
pair<int, int> to_coordinates(const string &pos)
{
    return {pos[0] - 'a', pos[1] - '1'};
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string start, destination;
        cin >> start >> destination;
        pair<int, int> start_pos = to_coordinates(start);
        pair<int, int> dest_pos = to_coordinates(destination);
        int result = min_knight_moves(start_pos, dest_pos);
        cout << result << endl;
    }
    return 0;
}
