class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;

        int *sum = new int[len];
        sum[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            sum[i] = sum[i-1] + nums[i];
        }

        for (int i = 0; i < len; ++i) {
            if (sum[len-1] - sum[i] == sum[i] - nums[i]) return i;
        }

        return -1;
    }
};