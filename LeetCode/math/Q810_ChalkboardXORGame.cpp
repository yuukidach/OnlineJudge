class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if ((nums.size()&1) == 0) return true;
        int tmp = 0;
        for (auto &num : nums) tmp ^= num;
        return !tmp;
    }
};

