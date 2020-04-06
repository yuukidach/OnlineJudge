class Solution {
public:
    string reorganizeString(string S) {
        int letter[26 + 1] = {0};
        int len = S.size();
        int maxl = 26;
        string res(len, '*');
        int pos = -2;

        for (int i = 0; i < len; ++i) {
            letter[S[i] - 'a']++;
            maxl = letter[S[i] - 'a'] > letter[maxl] ? S[i] - 'a' : maxl;
        }

        if (letter[maxl] > (len + 1 >> 1)) return "";

        while(letter[maxl]) {
            pos += 2;
            res[pos] = maxl + 'a';
            letter[maxl]--;
        }
        for (int i = 0; i < 26; ++i) {
            while (letter[i]) {
                pos = pos + 2 > len - 1 ? 1 : pos + 2;
                res[pos] = i + 'a';
                letter[i]--;
            }
        }

        return res;
    }
};