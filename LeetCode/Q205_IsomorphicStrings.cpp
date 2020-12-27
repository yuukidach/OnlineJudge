class Solution {
public:
    bool isIsomorphic(string s, string t) {
        string m;
        unordered_map<char, char> map;
        unordered_map<char, int> flag;
        int len = s.size();

        for (int i = 0; i < len; ++i) {
            if (map.find(s[i]) == map.end()) {
                map.emplace(s[i], t[i]);
                if (flag.find(t[i]) != flag.end()) return false;
                else flag.emplace(t[i], 1);
            }

            m += map[s[i]];
        }

        if (m == t) return true;
        return false;
    }
};