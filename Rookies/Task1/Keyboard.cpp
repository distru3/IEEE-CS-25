#include <iostream>
#include <string>
using namespace std;

int main()
{
    char direction;
    cin >> direction;
    string typedString;
    cin >> typedString;
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string result = "";
    for (char i : typedString)
    {
        size_t pos = keyboard.find(i);
        if (direction == 'R')
        {
            result += keyboard[pos - 1];
        }
        else if (direction == 'L')
        {
            result += keyboard[pos + 1];
        }
    }
    cout << result << endl;
    return 0;
}
