class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1, len = nums.size();
        int p0 = 0, p1 = 1;
        if (len == 1) return true;
        while(p1 < len) {
            if (nums[p0] > nums[p1]) {
                cnt--;
                if (cnt < 0) return false;
                if (p0 > 0 && nums[p0-1] > nums[p1])  nums[p1] = nums[p0];
            }
            p1++;
            p0++;
        }
        return true;
    }
};