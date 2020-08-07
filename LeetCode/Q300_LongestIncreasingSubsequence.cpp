class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len+1, 1);
        int res = 1;

        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                if (nums[j] > nums[i]) dp[j] = max(dp[j], dp[i]+1);
                res = max(res, dp[j]);
            }
        }

        return res;
    }
};