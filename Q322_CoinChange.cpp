class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] < 0) break;
                if (dp[i-coins[j]] == INT_MAX) continue;
                dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};