class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        if (len <= 1) return "";
        bool is_rplace = false;
        for (int i = 0; i < (len >> 1); ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                is_rplace = true;
                break;
            }
        }

        if (!is_rplace) palindrome[len-1] = 'b';

        return palindrome;
    }
};