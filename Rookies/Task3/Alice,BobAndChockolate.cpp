#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> chocolates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> chocolates[i];
    }
    int l = 0, r = n - 1;
    int tA = 0, tB = 0, cA = 0, cB = 0;
    while (l <= r)
    {
        if (tA <= tB)
        {
            tA += chocolates[l];
            l++;
            cA++;
        }
        else
        {
            tB += chocolates[r];
            r--;
            cB++;
        }
    }
    cout << cA << " " << cB << endl;
    return 0;
}
