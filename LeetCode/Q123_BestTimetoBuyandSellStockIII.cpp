class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int dp[days+1][3][2];

        dp[0][0][0] = 0;
        dp[0][1][0] = 0;
        dp[0][2][0] = 0;
        dp[0][0][1] = INT_MIN;
        dp[0][1][1] = INT_MIN;
        dp[0][2][1] = INT_MIN;

        for (int i = 1; i <= days; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j > 0) {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i-1]);       
                } else {
                    dp[i][j][0] = dp[i-1][j][0];
                }
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i-1]);
            }
        }

        return dp[days][2][0];
    }
};