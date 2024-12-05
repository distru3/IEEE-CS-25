#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int> &arr, int mi)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= mi)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int q;
    cin >> q;
    vector<int> results(q);
    for (int i = 0; i < q; i++)
    {
        int mi;
        cin >> mi;
        results[i] = binarySearch(prices, mi);
    }
    for (int i = 0; i < q; i++)
    {
        cout << results[i] << endl;
    }
    return 0;
}
