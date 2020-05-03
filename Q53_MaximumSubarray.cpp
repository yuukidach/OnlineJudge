class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int len = nums.size();

        int total = nums[0];
        for (int i = 1; i < len; ++i) {
            if (total < 0) {
                total = nums[i];
                res = max(res, total);
                continue;
            }
            total += nums[i];
            res = max(res, total);
        }

        return res;
    }
};