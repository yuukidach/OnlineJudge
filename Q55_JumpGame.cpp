class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int *dp = new int[50000];
        memset(dp, 0, sizeof(int)*50000);
        dp[0] = 1;

        for (int i = 0; i < len; ++i) {
            if (dp[i] != 1) continue;
            for (int j = 1; j <= nums[i]; ++j) {
                dp[i+j] = 1; 
            }
        }

        if (dp[nums.size()-1]) return true;
        return false;
    }
};