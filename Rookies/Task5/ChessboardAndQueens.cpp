#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<string> board(N);
bool column[N] = {0}, diag1[2 * N - 1] = {0}, diag2[2 * N - 1] = {0};
int ways = 0;
void solve(int row)
{
    if (row == N)
    {
        ways++;
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (board[row][col] == '.' && !column[col] && !diag1[row - col + N - 1] && !diag2[row + col])
        {
            column[col] = diag1[row - col + N - 1] = diag2[row + col] = true;
            solve(row + 1);
            column[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    solve(0);
    cout << ways << endl;
    return 0;
}
