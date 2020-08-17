class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size(), -1);
        int len = nums.size();

        for (int i = 0; i < 2 * len; ++i) {
            if (s.empty()) {
                s.emplace(i % len);
                continue;
            }

            while (!s.empty() && nums[s.top()] < nums[i%len]) {
                res[s.top()] = nums[i%len];
                s.pop();
            }
            s.emplace(i % len);
        }

        return res;
    }
};