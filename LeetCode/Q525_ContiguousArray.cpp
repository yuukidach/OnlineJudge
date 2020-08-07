class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        int *mark = new int[(len << 1) + 1];
        memset(mark, -1, sizeof(int) * (2*len+1));

        int sum = 0;
        int res = 0;
        for (int i = 0; i < len; ++i) {
            sum += (nums[i] << 1) - 1;
            if (sum == 0) {
                res = max(res, i+1);
                continue;
            }
            if (mark[sum+len] == -1) mark[sum+len] = i;
            else {
                res = max(res, i-mark[sum+len]);
            }
        }
        return res;
    }
};