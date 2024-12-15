#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long divideApples(vector<long long> &weights, int index, long long group1, long long group2)
{
    if (index == weights.size())
    {
        return abs(group1 - group2);
    }
    long long diff1 = divideApples(weights, index + 1, group1 + weights[index], group2);
    long long diff2 = divideApples(weights, index + 1, group1, group2 + weights[index]);
    return min(diff1, diff2);
}

int main()
{
    int n;
    cin >> n;
    vector<long long> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    long long result = divideApples(weights, 0, 0, 0);
    cout << result << endl;
    return 0;
}
