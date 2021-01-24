class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 0, pre = INT_MIN;
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] > pre) {
                cnt++;
            } else {
                cnt = 1;
            }
            pre = nums[i];
            res = max(res, cnt);
        }

        return res;
    }
};