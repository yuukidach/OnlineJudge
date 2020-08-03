class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        int dp[len+1][2];

        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = nums[0];

        for (int i = 2; i <= len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][0] + nums[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][1] + nums[i-1]);
        }

        if (len > 1) dp[len][1] = dp[len-1][1];

        return max(dp[len][0], dp[len][1]);
    }
};