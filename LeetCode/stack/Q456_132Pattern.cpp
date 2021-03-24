class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        deque<int> s;
        int len = nums.size();
        int two = INT_MIN;

        for (int i = len-1; i >= 0; --i) {
            if (nums[i] < two) return true; 
            while (!s.empty() && nums[i] > s.back()) {
                two = max(two, s.back());
                s.pop_back();
            }
            s.push_back(nums[i]);
        }
        return false;
    }
};