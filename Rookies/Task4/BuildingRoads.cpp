#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int city = q.front();
        q.pop();
        for (int neighbor : adj[city])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n + 1, false);
    vector<int> representatives;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            representatives.push_back(i);
            bfs(i, adj, visited);
        }
    }
    int roads_needed = representatives.size() - 1;
    cout << roads_needed << endl;
    for (int i = 1; i < representatives.size(); i++)
    {
        cout << representatives[i - 1] << " " << representatives[i] << endl;
    }
    return 0;
}
