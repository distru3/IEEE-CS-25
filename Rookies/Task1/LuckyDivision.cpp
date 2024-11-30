#include <iostream>
using namespace std;

int main()
{
    int luck[13] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 774, 777};
    bool isLucky = false;
    int x;
    cin >> x;
    for (int i = 0; i < 12; i++)
    {
        if (x % luck[i] == 0)
        {
            isLucky = true;
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}