class Solution {
public:
    int numOfWays(int n) {
        int mod_num = pow(10, 9) + 7;
        long dp[5001][2] = {0};
        dp[1][0] = 1+1+1+1+1+1;
        dp[1][1] = 1+1+1+1+1+1;
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = ((dp[i-1][0] << 1) + (dp[i-1][1] << 1)) % mod_num;
            dp[i][1] = ((dp[i-1][0] << 1) + dp[i-1][1] * 3) % mod_num;
        }

        return (dp[n][0] + dp[n][1]) % mod_num;
    }