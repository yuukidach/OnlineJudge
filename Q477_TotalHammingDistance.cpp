class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int res = 0;

        for(int i = 0; i < sizeof(int)*8; ++i) {
            int bits[2] = {0, 0};
            for(int j = 0; j < len; ++j){
                if (nums[j] & (1 << i)) bits[1]++;
                else bits[0]++;
            }
            res += bits[0] * bits[1];
        }

        return res;
    }
};