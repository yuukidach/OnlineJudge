class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxs, mins;
        int n = nums.size();
        int l = 0, r = 0;
        int gap = 0;
        int res = 0;
        while(r < n) {
            while(!mins.empty() && nums[r] < mins.back()) {
                mins.pop_back();
            }
            mins.push_back(nums[r]);
            while(!maxs.empty() && nums[r] > maxs.back()) {
                maxs.pop_back();
            }
            maxs.push_back(nums[r]);
            if (maxs.front() - mins.front() > limit) {
                if (nums[l] == mins.front()) mins.pop_front();
                if (nums[l] == maxs.front()) maxs.pop_front();
                l++;
            }
            r++;
            res = max(res, r-l);
        }

        return res;
    }
};