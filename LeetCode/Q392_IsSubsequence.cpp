class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        int pos1 = 0, pos2 = 0;

        while (pos2 + len1 - pos1 <= len2 && pos2 < len2 && pos1 < len1) {
            if (t[pos2] != s[pos1]) pos2++;
            else {
                pos1++;
                pos2++;
            }
        }

        if(pos1 >= len1) return true;
        return false; 
    }
};