class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;

        int l = 0;
        int res = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            s.insert(nums[i]);
            int gap = abs(*(--s.end()) - *(s.begin()));
            while (gap > limit && !s.empty()) {
                auto it = s.find(nums[l]);
                s.erase(it);
                l++;
                gap = abs(*(--s.end()) - *(s.begin()));
            }

            res = s.size() > res ? s.size() : res;
        }

        return res;
    }
};