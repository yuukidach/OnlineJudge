class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int map[26];
        string s = "croak";
        memset(map, 0, sizeof(int)*26);

        for(auto c : croakOfFrogs) {
            if (s.find(c) == std::string::npos) return -1;
            map[c-'a']++;

            int last = map['c'-'a'];
            for (int i = 1; i < 5; ++i) {
                if (map[s[i]-'a'] > last) return -1;
                last = map[s[i]-'a'];
            }
        }

        int cnt = map['c'-'a'];
        for (int i = 1; i < 5; ++i) {
            if (map[s[i]-'a'] != cnt) return -1;
        }

        int ans = 0, res = 0, used = 0;
        for (auto c : croakOfFrogs) {
            if (c == 'c') {
                if (res == 0) ans++;
                else {
                    res--;
                }
            } else if (c == 'k') {
                res++;
            }
        }

        return ans;
    }
};