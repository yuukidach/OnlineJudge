class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        int dp[len];

        dp[0] = nums[0];
        if (dp[0] == k) res++;

        for (int i = 1; i < len; ++i) {
            dp[i] = dp[i-1] + nums[i];
            if (dp[i] == k) res++;    
        }

        for (int i = 1; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                int cnt = dp[j] - dp[i-1];
                if (cnt == k) res++;
            }
        }

        return res;
    }
};