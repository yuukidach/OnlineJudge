class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = 0;
        while(r < n) {
            if (nums[r] == 0) l = r + 1;
            r++;
            cnt = max(cnt, r - l);
        }
        return cnt;
    }
};