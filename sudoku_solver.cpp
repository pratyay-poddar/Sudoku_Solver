#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SudokuSolver3x3
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[row][i] == dig)
                return false;
            if (board[i][col] == dig)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char dig = '1'; dig <= '3'; dig++)
                    {
                        if (isSafe(board, row, col, dig))
                        {
                            board[row][col] = dig;
                            if (solve(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void display(const vector<vector<char>> &board)
    {
        cout << "\nGrid State:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    SudokuSolver3x3 engine;
    vector<vector<char>> board(3, vector<char>(3));

    cout << "Enter 3x3 Sudoku (3 rows, 3 characters each. Use 1-9 or '.')" << endl;

    for (int i = 0; i < 3; i++)
    {
        string line;
        cout << "Row " << i + 1 << ": ";
        cin >> line;

        if (line.length() != 3)
        {
            cout << "Each row must have exactly 3 characters. You entered " << line.length() << "." << endl;
            return 1;
        }

        for (int j = 0; j < 3; j++)
        {
            char c = line[j];
            if (c != '.' && (c < '1' || c > '9'))
            {
                cout << "Invalid character '" << c << "'. Only 1, 2, 3...9 and '.' are allowed." << endl;
                return 1;
            }
            board[i][j] = c;
        }
    }

    if (engine.solve(board))
    {
        cout << "\nSuccess!" << endl;
        engine.display(board);
    }
    else
    {
        cout << "\nHas no solution" << endl;
    }

    return 0;
}
