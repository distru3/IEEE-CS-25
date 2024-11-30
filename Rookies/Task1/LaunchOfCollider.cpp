#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string directions;
    cin >> directions;
    vector<long long> positions(n);
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    int minCollisionTime = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (directions[i] == 'R' && directions[i + 1] == 'L')
        {
            int collisionTime = (positions[i + 1] - positions[i]) / 2;
            minCollisionTime = min(minCollisionTime, collisionTime);
        }
    }
    if (minCollisionTime == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minCollisionTime << endl;
    }
    return 0;
}
