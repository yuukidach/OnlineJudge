class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h == 0) return 0;
        int w = matrix[0].size();
        int dp[h][w];

        int res = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                        res = max(res, 1);
                        continue;
                    }
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + 1;
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res*res;
    }
};