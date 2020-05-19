class Solution {
public:
    int checkPalindrome(string s) {
        int len = s.size();
        int mid = (len - 1) >> 1;

        for (int i = mid - (len & 1); i >= 0; --i) {
            if (s[i] != s[len-1-i]) return i;
        }

        return -1;
    }

    bool validPalindrome(string s) {
        int len = s.size();
        int mid = (len - 1) >> 1;
        int i = 0;
        int j = len-1;
        bool flag = false;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            } else {
                string a = s, b = s;
                a.erase(i, 1);
                b.erase(j, 1);
                if (checkPalindrome(a) != -1 && checkPalindrome(b) != -1) return false;
                else return true;
            }
        }

        return true;
    }
};
