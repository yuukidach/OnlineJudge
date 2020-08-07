class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);

        int l = 1, r = 1;
        for (int i = 0; i < len; ++i) {
            res[i] *= l;
            l *= nums[i];

            res[len-1-i] *= r;
            r *= nums[len-1-i];
        }

        return res;
    }
};