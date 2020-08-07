class Solution {
public:
    bool is_conflict(vector<string> &board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            int pos = col - row + i;
            int pos2 = col + row - i;
            if (pos >= 0 && board[i][pos] == 'Q') return true;
            if (pos2 < board.size() && board[i][pos2] == 'Q') return true;
            if (board[i][col] == 'Q') return true;
        }

        return false;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &board, int row) {
        if (row == board.size()) res.push_back(board);

        for (int i = 0; i < board.size(); ++i) {
            if (is_conflict(board, row, i)) continue;

            board[row][i] = 'Q';
            backtrack(res, board, row+1);
            board[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res;
    }
};