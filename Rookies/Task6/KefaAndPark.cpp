#include <iostream>
#include <vector>
using namespace std;

void dfs(int current, int parent, int consecutive_cats,
         const vector<vector<int>> &graph, const vector<int> &has_cat,
         int max_cats, int &restaurant_count)
{
    if (has_cat[current])
    {
        consecutive_cats++;
    }
    else
    {
        consecutive_cats = 0;
    }

    if (consecutive_cats > max_cats)
    {
        return;
    }
    if (graph[current].size() == 1 && current != 0)
    {
        restaurant_count++;
        return;
    }
    for (int next : graph[current])
    {
        if (next != parent)
        {
            dfs(next, current, consecutive_cats, graph, has_cat, max_cats, restaurant_count);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> has_cat(n);
    for (int i = 0; i < n; i++)
    {
        cin >> has_cat[i];
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int restaurant_count = 0;
    dfs(0, -1, 0, graph, has_cat, m, restaurant_count);
    cout << restaurant_count << endl;
    return 0;
}
