#include <iostream>
using namespace std;

bool isValid(int ans, int n, int k)
{
    int init = ans;
    while (ans > 0)
    {
        ans = ans / k;
        init += ans;
    }
    if (init >= n)
        return true;
    else
        return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int left = k, right = n, v = n, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (isValid(mid, n, k))
        {
            v = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << v;
}