#include <iostream>
using namespace std;

void weirdAlgorithm(long long n)
{
    cout << n << " ";
    if (n == 1)
        return;
    if (n % 2 == 0)
        weirdAlgorithm(n / 2);
    else
        weirdAlgorithm(3 * n + 1);
}

int main()
{
    long long n;
    cin >> n;
    weirdAlgorithm(n);
    return 0;
}
