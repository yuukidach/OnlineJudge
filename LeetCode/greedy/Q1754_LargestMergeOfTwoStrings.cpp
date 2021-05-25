class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res = "";
        while (!word1.empty() && !word2.empty()) {
            if (word1 > word2) {
                res += word1[0];
                word1.erase(word1.begin());
            } else {
                res += word2[0];
                word2.erase(word2.begin());
            }
        }

        if (!word1.empty()) res += word1;
        if (!word2.empty()) res += word2;

        return res;
    }
};