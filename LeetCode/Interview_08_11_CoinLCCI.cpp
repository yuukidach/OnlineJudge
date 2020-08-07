class Solution {
public:
    int waysToChange(int n) {
        const int m = 1000000007;
        int coins[] = {1, 5, 10, 25};
        vector<vector<int>> dp(4, vector<int>(n+1, 1));

        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j >= coins[i])
                    dp[i][j] = (dp[i-1][j] + dp[i][j-coins[i]]) % m;
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[3][n];
    }
};