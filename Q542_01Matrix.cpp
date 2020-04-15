class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int ylen = matrix.size();
        int xlen = matrix[0].size();

        vector<vector<int>> m(ylen, vector<int>(xlen, 11111));

        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, 1, 0};

        for (int i = 0; i < ylen; ++i) {
            for (int j = 0; j < xlen; ++j) {
                if (matrix[i][j] == 0) {
                    m[i][j] = 0;
                    continue;
                }
                for (int k = 0; k < 2; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0) continue;
                    m[i][j] = min(m[i][j], m[ny][nx]+1);
                }
            }
        }

        for (int i = ylen-1; i > -1; --i) {
            for (int j = xlen-1; j > -1; --j) {
                for (int k = 2; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny >= ylen || nx >= xlen) continue;
                    m[i][j] = min(m[i][j], m[ny][nx]+1);
                }
            }
        }

        return m;
    }
};