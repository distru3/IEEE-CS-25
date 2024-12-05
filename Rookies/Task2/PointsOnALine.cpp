#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &x, int i, int d)
{
    int low = i, high = x.size() - 1, result = i;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x[mid] - x[i] <= d)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    long long totalGroups = 0;
    for (int i = 0; i < n; i++)
    {
        int j = binarySearch(x, i, d);
        int k = j - i + 1;
        if (k >= 3)
        {
            totalGroups += (long long)(k - 2) * (k - 1) / 2;
        }
    }
    cout << totalGroups << endl;
    return 0;
}
