class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res;
        int gap = INT_MAX;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int new_target = target - nums[i];
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > new_target) r--;
                else if (sum < new_target) l++;
                else return target;

                int sgap = abs(sum - new_target);
                if (sgap < gap) {
                    gap = sgap;
                    res = nums[i] + sum;
                }
            }
        }

        return res;
    }
};