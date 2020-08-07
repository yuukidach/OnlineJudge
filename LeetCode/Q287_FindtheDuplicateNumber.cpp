class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                if ((nums[i] ^ nums[j]) == 0) return nums[i];
            }
        }

        return -1;
    }
};
