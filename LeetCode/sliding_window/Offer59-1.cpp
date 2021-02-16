class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0, r = 0;
        deque<int> q;

        while (r < nums.size()) {
            while (!q.empty() && nums[r] > q.back()) q.pop_back();
            q.push_back(nums[r]);
            r++;

            while (r - l > k) {
                if (nums[l] == q.front()) q.pop_front();
                l++;
            }

            res.push_back(q.front());
        }
        
        for (int i = 0; i < k - 1; ++i) res.erase(res.begin());
        return res;
    }
};