class Solution {
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r == 0) return;
        int c = board[0].size();

        queue<pair<int, int>> q;
        
        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') {
                q.emplace(i, 0);
                board[i][0] = 'T';
            }
            if (board[i][c-1] == 'O') {
                q.emplace(i, c-1);
                board[i][c-1] = 'T';
            }
        }

        for (int i = 0; i < c; ++i) {
            if (board[0][i] == 'O') {
                q.emplace(0, i);
                board[0][i] = 'T';
            }
            if (board[r-1][i] == 'O') {
                q.emplace(r-1, i);
                board[r-1][i] = 'T';
            }
        }

        while (!q.empty()) {
            pair<int, int> dot = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int ny = dot.first + dy[i];
                int nx = dot.second + dx[i];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (board[ny][nx] == 'O') {
                    q.emplace(ny, nx);
                    board[ny][nx] = 'T';
                }
            }
        }

        for (int i =  0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                switch(board[i][j]) {
                case 'T': board[i][j] = 'O'; break;
                case 'O': board[i][j] = 'X'; break;
                }
            }
        }

        return;
    }
};