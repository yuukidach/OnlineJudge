class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cnt;
        int res = 0;

        for (int num : nums) {
            cnt.insert(num);
        }

        for (int num : nums) {
            if (!cnt.count(num-1)) {
                int nownum = num + 1;
                int len = 1;

                while (cnt.count(nownum)) {
                    nownum++;
                    len++;
                }

                res = max(res, len);
            }
        }

        return res;
    }
};