#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pairs(int k, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int count = 0;
    int l = 0, r = 0;
    while (r < arr.size())
    {
        int diff = arr[r] - arr[l];
        if (diff == k)
        {
            count++;
            l++;
            r++;
        }
        else if (diff < k)
        {
            r++;
        }
        else
        {
            l++;
        }
        if (l == r)
        {
            r++;
        }
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << pairs(k, arr) << endl;
    return 0;
}
