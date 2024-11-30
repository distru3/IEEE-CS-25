#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> heights[i];
  }
  int maxIndex = 0;
  int minIndex = 0;
  for (int i = 1; i < n; i++)
  {
    if (heights[i] > heights[maxIndex])
    {
      maxIndex = i;
    }
    if (heights[i] <= heights[minIndex])
    {
      minIndex = i;
    }
  }
  int seconds = maxIndex + (n - 1 - minIndex);
  if (maxIndex > minIndex)
  {
    seconds--;
  }
  cout << seconds << endl;
  return 0;
}