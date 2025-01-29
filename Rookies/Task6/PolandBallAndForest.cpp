#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<int, int> find_farthest_node(int current, int parent, const vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[current] = true;
    pair<int, int> result = {current, 0};

    for (int next : graph[current])
    {
        if (!visited[next] && next != parent)
        {
            auto temp = find_farthest_node(next, current, graph, visited);
            if (temp.second + 1 > result.second)
            {
                result = {temp.first, temp.second + 1};
            }
        }
    }

    return result;
}

bool is_valid_sequence(int n, const vector<int> &p, const vector<vector<int>> &graph)
{
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            auto farthest = find_farthest_node(i, -1, graph, visited);
            vector<bool> temp_visited(n + 1, false);
            auto actual_farthest = find_farthest_node(farthest.first, -1, graph, temp_visited);
            vector<int> max_dist_nodes;
            for (int j = 1; j <= n; j++)
            {
                if (temp_visited[j] && actual_farthest.second == 0)
                {
                    max_dist_nodes.push_back(j);
                }
            }

            if (max_dist_nodes.empty())
                continue;
            int min_id = max_dist_nodes[0];
            for (int node : max_dist_nodes)
            {
                min_id = min(min_id, node);
            }

            if (p[i - 1] != min_id)
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<vector<int>> graph(n + 1);
    set<int> tree_roots;
    for (int i = 0; i < n; i++)
    {
        if (p[i] != i + 1)
        {
            graph[i + 1].push_back(p[i]);
            graph[p[i]].push_back(i + 1);
        }
        tree_roots.insert(i + 1);
    }

    int tree_count = 0;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            find_farthest_node(i, -1, graph, visited);
            tree_count++;
        }
    }

    cout << tree_count << endl;

    return 0;
}