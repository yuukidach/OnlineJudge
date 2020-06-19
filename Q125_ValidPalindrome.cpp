class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
                str += c;
            } else if (c >= 'a' && c <= 'z') {
                str += c;
            } else if (c >= '0' && c <= '9') {
                str += c;
            }
        }

        int len = str.size();
        for (int i = 0; i < len / 2; ++i) {
            if (str[i] != str[len - 1 - i]) return false;
        }

        return true;
    }
};