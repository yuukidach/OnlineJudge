class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        if (len == 3) return max(nums[0]+nums[2], nums[1]);
        int dp[len];
        memset(dp, 0, sizeof(int) * len);

        int res = INT_MIN;

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        res = max(dp[0], dp[1]);
        res = max(res, dp[2]);

        for (int i = 3; i < len; ++i) {
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
            res = max(res, dp[i]);
        }

        return res;
    }
};
