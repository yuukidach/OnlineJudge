class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, column;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    row.emplace(i);
                    column.emplace(j);
                }
            }
        }

        for (auto &r : row) {
            fill(matrix[r].begin(), matrix[r].end(), 0);
        }

        for (auto &c : column) {
            for (int i = 0; i < n; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};