#include <iostream>
#include <set>
using namespace std;

set<string> uniquePermutations;

void generatePermutations(string &s, int index)
{
    if (index == s.length())
    {
        uniquePermutations.insert(s);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        generatePermutations(s, index + 1);
        swap(s[index], s[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    generatePermutations(s, 0);
    cout << uniquePermutations.size() << endl;
    for (const string &str : uniquePermutations)
    {
        cout << str << endl;
    }
    return 0;
}
