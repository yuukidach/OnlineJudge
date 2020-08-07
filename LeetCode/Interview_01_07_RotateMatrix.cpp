class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (i == j) continue;
                matrix[i][j] ^= matrix[j][i];
                matrix[j][i] ^= matrix[i][j];
                matrix[i][j] ^= matrix[j][i];
            }
        }

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < (len >> 1); ++j) {
                matrix[i][j] ^= matrix[i][len-1-j];
                matrix[i][len-1-j] ^= matrix[i][j];
                matrix[i][j] ^= matrix[i][len-1-j];
            }
        }
    }
};