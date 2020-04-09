class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        int sum1 = 0, sum2 = 0;
        
        sort(nums.rbegin(), nums.rend());
        
        int l = 0, r = len-1;
        sum1 += nums[l];
        sum2 += nums[r];
        res.push_back(nums[l]);
        
        while (l < r) {
            while (sum1 > sum2) {
                r--;
                if (l >= r) break;
                sum2 = sum2 + nums[r];
            }
            
            while (sum1 <= sum2 && l < r) {
                sum1 += nums[++l];
                res.push_back(nums[l]);
            }
        }
        
        return res;
    }
};