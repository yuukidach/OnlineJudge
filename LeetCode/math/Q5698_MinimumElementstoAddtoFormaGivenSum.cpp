class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0, res = 0, g = goal;
        for (auto &num : nums) sum += num;
        g = abs((long)goal - sum);
        res = (g + limit - 1) / limit;
        return res;
    }
};