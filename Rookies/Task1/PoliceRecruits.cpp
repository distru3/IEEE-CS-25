#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int untreated = 0, officers = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            if (officers != 0)
            {
                officers--;
            }
            else
            {
                untreated++;
            }
        }
        else
        {
            officers += x;
        }
    }
    cout << untreated;
}