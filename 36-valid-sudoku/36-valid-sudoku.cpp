class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            for (int i = 0; i < 9; i++)
            {
                vector<int> row(10, 0), col(10, 0), box(10, 0);
                for (int j = 0; j < 9; j++)
                {
                    int val;

                   	// row
                    if (board[i][j] != '.')
                    {
                        int val = board[i][j] - '0';
                        row[val]++;
                        if (row[val] > 1) return false;
                    }

                   	// col
                    if (board[j][i] != '.')
                    {
                        int val = board[j][i] - '0';
                        col[val]++;
                        if (col[val] > 1) return false;
                    }

                   	// box
                    int x = 3 *(i / 3) + j / 3, y = 3 *(i % 3) + j % 3;
                    if (board[x][y] != '.')
                    {
                        val = board[x][y] - '0';
                        box[val]++;
                        if (box[val] > 1) return false;
                    }
                }
            }
            return true;
        }
};