class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];

        for (auto &num : nums) {
            if (num < res) {
                res = num;
                break;
            }
        }

        return res;
    }
};