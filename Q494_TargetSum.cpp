class Solution {
public:

    /**
    A - B = target
    A = target + B
    2A + target + A + B
    A = (target + A + B) / 2 = (target + sum) / 2 
    **/
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum < S) return 0;
        int target = S + sum;
        if (target & 1) return 0;
        target >>= 1;

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 0; i < len; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] + dp[j-nums[i]];
            }
        } 

        return dp[target];
    }
};