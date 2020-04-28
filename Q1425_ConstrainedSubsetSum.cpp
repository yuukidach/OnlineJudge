class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(len, INT_MIN);
        int res = INT_MIN;
        int idx = -1;

        for (int i = 0; i < len; ++i) {
            res = max(res, nums[i]);
            if (nums[i] > 0 && idx == -1) {
                idx = i;
                dp[i] = nums[i];
                break;
            }
        }

        if (idx == -1) return res;

        int last = -1;
        for (int j = idx; j < len; ++j) {
            dp[j] = nums[j];
            for (int m = 1; m <= k; ++m) {
                if (j - m < idx) break;
                dp[j] = max(dp[j-m] + nums[j], dp[j]);
                if (last == j-m) break;
            }
            if (nums[j] >= 0) {
                last = j;
            }
        }

        for (int i = idx; i < len; ++i) {
            res = max(res, dp[i]);
        }

        return res;
    }
};