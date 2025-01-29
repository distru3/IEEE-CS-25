#include <iostream>
#include <vector>
using namespace std;

int dfs(int current, int parent, vector<vector<pair<int, int>>> &graph)
{
    int maxCost = 0;
    for (auto &neighbor : graph[current])
    {
        int nextNode = neighbor.first;
        int cost = neighbor.second;
        if (nextNode != parent)
        {
            maxCost = max(maxCost, cost + dfs(nextNode, current, graph));
        }
    }

    return maxCost;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    int result = dfs(0, -1, graph);
    cout << result << endl;
    return 0;
}