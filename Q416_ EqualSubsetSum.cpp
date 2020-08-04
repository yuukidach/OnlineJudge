class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }

        if ((sum & 1) == 1) return false;

        int target = sum >> 1;

        vector<bool> dp(target+2, false);

        for (int i = 0; i < len; ++i) {
            for (int j = target; j > nums[i]; --j) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
            dp[min(nums[i], target+1)] = true;
        }

        return dp[target];
    }
};