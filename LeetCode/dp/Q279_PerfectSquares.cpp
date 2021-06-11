class Solution {
public:
    int numSquares(int n) {
        vector<int> val;
        for(int i = 1; i <= 100; ++i) val.emplace_back(i*i);

        int len = n +5;
        vector<int> dp(len, INT_MAX-20000);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (i - val[j] < 0) break;
                dp[i] = min(dp[i], dp[i-val[j]]+1);
            }
        }

        return dp[n];
    }
};