#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

bool isSafe(int r, int c, vector<vector<int>> &board, int val)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        // check column
        if (board[i][c] == val)
            return false;
        // check row
        if (board[r][i] == val)
            return false;
        // 3*3 matrix check
        if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val)
            return false;
    }
    return true;
}

// Suduku solver 
// ----------------
// Time complexity: 9^m where m is the no of empty spaces.
// Space complexity: O(1)
bool solve(vector<vector<int>> &board)
{
    int n = board.size();
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            // if empty
            if (board[r][c] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(r, c, board, val))
                    {
                        board[r][c] = val;
                        // recursive call
                        bool forwardPossible = solve(board);
                        if (forwardPossible)
                            return true;
                        else
                        {
                            // backtrack
                            board[r][c] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> a = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // vector<vector<int>> a = {{9, 0, 3, 5, 0, 6, 0, 1, 4}, {0, 6, 5, 7, 0, 0, 0, 0, 0}, {1, 0, 7, 0, 0, 0, 5, 0, 0}, {3, 9, 0, 0, 2, 0, 0, 0, 5}, {0, 5, 0, 3, 0, 0, 0, 7, 6}, {0, 8, 1, 4, 0, 0, 2, 9, 3}, {5, 3, 0, 9, 0, 4, 0, 0, 0}, {4, 0, 0, 6, 5, 0, 9, 0, 0}, {0, 7, 0, 0, 3, 0, 4, 0, 2}};
    time_t t1;
    srand(time(&t1));
    a[0][0]=(rand()*rand())%10;
    int p=rand()%25;
    while(p--){
        // a[(p*rand())%9][p*rand()%9]=(rand()*rand())%10;
    }
    cout << solve(a) << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}