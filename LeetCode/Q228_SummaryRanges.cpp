class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if (n == 0) return res;
        int pre = nums[0];        

        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            if (nums[i] == pre + cnt + 1) {
                cnt++;
                continue;
            }

            if (cnt == 0) {
                res.emplace_back(to_string(pre));
            } else {
                string cell = to_string(pre) + "->" + to_string(pre+cnt);
                res.emplace_back(cell);
            }

            pre = nums[i];
            cnt = 0;
        }

        if (cnt == 0) {
            res.emplace_back(to_string(pre));
        } else {
            string cell = to_string(pre) + "->" + to_string(pre+cnt);
            res.emplace_back(cell);
        }
        return res;
    }
};