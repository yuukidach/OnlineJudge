class Solution {
public:
    bool checkOnesSegment(string s) {
        int len = s.size();
        if (len == 0) return false;
        if (len == 1 && s[0] == '0') return false;
        
        int l, r;
        for (l = 0; l < len; ++l) {
            if (s[l] == '1') break;
        }
        
        for (r = l; r < len; ++r) {
            if (s[r] == '0') break;
        }
        
        for (int i = r + 1; i < len; ++i) {
            if (s[i] == '1') return false;
        }
        
        return true;
    }
};