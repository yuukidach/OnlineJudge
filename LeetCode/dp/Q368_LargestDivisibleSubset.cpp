class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> res;
        int dp[1005] = {0};
        int idx = 0;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) dp[i] = max(dp[i], dp[j]+1);
            }

            if (dp[i] > dp[idx]) idx = i;
        }

        int cnt = dp[idx];
        for (int i = idx; i >= 0; --i) {
            if (nums[idx] % nums[i] == 0 && dp[i] == cnt) {
                res.push_back(nums[i]);
                cnt--;
                idx = i;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};