class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k;
        int sum = 0;
        for (int i = 0; i < r; ++i) sum += nums[i];
        double res = sum;
        while (r < nums.size()) {
            sum -= nums[l];
            sum += nums[r];
            res = res > sum ? res : sum;
            l++;
            r++;
        }
        return res / k;
    }
};