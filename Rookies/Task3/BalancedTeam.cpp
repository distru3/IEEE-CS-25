#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> skills(n);
    for (int i = 0; i < n; i++)
    {
        cin >> skills[i];
    }
    sort(skills.begin(), skills.end());
    int left = 0, right = 0, max_team_size = 0;
    while (right < n)
    {
        if (skills[right] - skills[left] <= 5)
        {
            max_team_size = max(max_team_size, right - left + 1);
            right++;
        }
        else
        {
            left++;
        }
    }
    cout << max_team_size << endl;
    return 0;
}
