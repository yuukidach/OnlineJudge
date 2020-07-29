class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();
        int dp[r][c];

        for (int i = 0; i < c; ++i) dp[r-1][i] = triangle[r-1][i];

        for (int i = r-2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                int cnt1 = INT_MIN, cnt2 = INT_MIN;
                cnt1 = triangle[i][j] + dp[i+1][j];
                cnt2 = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(cnt1, cnt2);
            }
        }

        return dp[0][0];
    }
};