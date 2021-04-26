class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int dp[1005];
        memset(dp, 0, sizeof(int) * 1005);

        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < len && i >= nums[j]; ++j) {
                long tmp = (long)dp[i] + dp[i-nums[j]];
                if (tmp > INT_MAX) break;
                dp[i] += dp[i-nums[j]];
            }
        }

        return dp[target];
    }
};