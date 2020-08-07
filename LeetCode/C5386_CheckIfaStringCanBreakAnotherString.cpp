class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int len = s1.size();

        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (s1[i] >= s2[i]) cnt++;
            else break;
        }
        
        if (cnt == len) return true;
        
        cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (s1[i] <= s2[i]) cnt++;
            else break;
        }
        
        if (cnt == len) return true;
        
        return false;
    }
};