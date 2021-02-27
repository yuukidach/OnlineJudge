class Solution {
public:
    int longestSubstring(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            if (count(s.begin(), s.end(), s[i]) < k) {
                return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i+1, s.size()-i-1), k));
            }
        }

        return s.size();
    }
};