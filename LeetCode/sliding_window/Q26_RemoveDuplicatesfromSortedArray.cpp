class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = INT_MIN;
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == pre) {
                nums.erase(nums.begin() + i);
            } else {
                pre = nums[i];
                ++i;
            }
        } 
        return nums.size();
    }
};