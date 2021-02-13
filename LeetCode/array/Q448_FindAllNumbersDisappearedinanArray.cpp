class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (auto num : nums) {
            int a = abs(num)-1;
            nums[a] = nums[a] > 0 ? -nums[a] : nums[a];
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};