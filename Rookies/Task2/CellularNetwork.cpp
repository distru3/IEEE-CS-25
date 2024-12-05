#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int city, const vector<int> &towers)
{
    int low = 0, high = towers.size() - 1;
    int x = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        x = min(x, abs(towers[mid] - city));
        if (towers[mid] < city)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return x;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cities(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cities[i];
    }
    vector<int> towers(m);
    for (int i = 0; i < m; i++)
    {
        cin >> towers[i];
    }
    int dis = 0;
    for (int city : cities)
    {
        int init = binarySearch(city, towers);
        dis = max(dis, init);
    }
    cout << dis << endl;
    return 0;
}
