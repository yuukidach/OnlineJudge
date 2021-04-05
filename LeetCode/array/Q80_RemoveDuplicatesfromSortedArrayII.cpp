class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int pre = nums[0], cnt = 0;
        for (int i = 1; i < nums.size();) {
            if (nums[i] != pre) {
                cnt = 0;
                pre = nums[i];
            } else {
                cnt++;
            }
            if (cnt > 1) {
                nums.erase(nums.begin() + i);
            } else {
                ++i;
            }
        }

        return nums.size();
    }
};