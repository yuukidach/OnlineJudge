class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), r = 0;
        unordered_set<int> mark;
        int res = 0;
        for (int i = 0; i < len && r < len; ++r) {
            while (mark.count(s[r]) == 1) {
                mark.erase(s[i++]);
            }
            mark.insert(s[r]);
            res = res > mark.size() ? res : mark.size();
        }
        return res;
    }
};