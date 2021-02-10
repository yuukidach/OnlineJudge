class Solution {
public:
    bool checkEqual(int *a1, int *a2) {
        for (int i = 0; i < 26; ++i) {
            if (a1[i] != a2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int f1[26] = {0};
        int f2[26] = {0};
        for (auto c : s1) f1[c-'a']++;
        
        int l = 0, r = 0;
        while(r < s2.size()) {
            if (f1[s2[r] - 'a'] == 0) {
                r++;
                l=r;
                memset(f2, 0, 26*sizeof(int));
                continue;
            }

            f2[s2[r] - 'a']++;
            r++;
            
            while(f2[s2[l] - 'a'] > f1[s2[l] - 'a']) {
                f2[s2[l] - 'a']--;
                l++;
            }

            if (checkEqual(f1, f2)) return true;
        }

        return false;
    }
};