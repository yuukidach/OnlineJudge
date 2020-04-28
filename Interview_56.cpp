class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        int a = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            a ^= nums[i];
        }

        int mask = 0;
        while ((a & (1 << mask)) == 0) mask++;
        int b = 0;
        a = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] & (1 << mask)) a ^= nums[i];
            else b ^= nums[i];
        }

        res.push_back(a);
        res.push_back(b);

        return res;
    }
};