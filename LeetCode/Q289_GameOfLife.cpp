class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int xlen = board[0].size();
        int ylen = board.size();

        for (int i = 0; i < ylen; ++i) {
            for (int j = 0; j < xlen; ++j) {
                int sum = 0;
                for (int k = 0; k < 8; ++k) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx < 0 || nx >= xlen || ny < 0 || ny >= ylen) continue;
                    sum += (board[ny][nx] & 1);
                }

                if (sum == 3) {
                    board[i][j] |= 1 << 1;
                } else if (sum == 2) {
                    board[i][j] |= board[i][j] << 1;
                }
            }
        }

        for (int i = 0; i < ylen; ++i) {
            for (int j = 0; j < xlen; ++j) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};