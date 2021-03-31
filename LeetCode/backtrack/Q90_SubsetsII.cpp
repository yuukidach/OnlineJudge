class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int len = nums.size();

        vector<int> tmp = {};
        res.push_back(tmp);
        for (int i = 0; i < len; ++i) {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }

        for (int i = 0; i < res.size(); ++i) {
            for (int j = i+1; j < res.size(); ++j) {
                if (res[i] == res[j]) {
                    res.erase(res.begin()+j);
                    j--;
                }
            }
        }

        return res;
    }
};