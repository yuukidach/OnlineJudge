class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, vector<int> &v) {
        if (nums.size() == 0) {
            res.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            v.push_back(n);
            nums.erase(nums.begin()+i);
            dfs(nums, v);
            v.pop_back();
            nums.insert(nums.begin()+i, n);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        dfs(nums, v);
        return res;
    }
};