class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1111111);

        dp[0] = 0;

        int r = 0;
        for (int i = 0; i < len; ++i) {
            if (i+nums[i] <= r) continue;
            for (int j = 1; j <= nums[i]; ++j) {
                if (i+j >= len) break;
                dp[i+j] = min(dp[i+j], dp[i]+1);
                r = max(r, i+j);
            }
        }

        return dp[len-1];
    }
};