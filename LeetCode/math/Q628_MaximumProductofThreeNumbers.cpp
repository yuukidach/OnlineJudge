class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int res;
        res = nums[0] * nums[1] * nums[2];
        if (nums.size() == 3) return res;
        res = max(nums[1] * nums[2] * nums[3], res);

        int n = nums.size();
        res = max(res, nums[n-1] * nums[n-2] * nums[0]);
        return res;
    }
};