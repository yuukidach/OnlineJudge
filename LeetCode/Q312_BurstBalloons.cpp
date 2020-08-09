class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(len+3, vector<int>(len+3, 0));

        for (int i = len; i > 0; --i) {
            for (int j = i; j <= len; ++j) {
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1]);
                }
            }
        }

        return dp[1][len];
    }
};