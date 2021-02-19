class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i]) == 0) {
                m[nums[i]] = {1, i, i};
            } else {
                m[nums[i]][0]++;
                m[nums[i]][2] = i;
            }
        }

        int res = 0, cnt = 0;
        for (auto [key, val] : m) {
            if (val[0] > cnt) {
                cnt = val[0];
                res = val[2] - val[1] + 1;
            } else if (val[0] == cnt) {
                res = min(res, val[2] - val[1] + 1);
            }
        }

        return res;
    }
};