class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};

        vector<string> res;
        for (string & word : words) {
            int flag = 0;
            for (int i = 0; i < word.size(); ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (s[j].find(word[i]) != string::npos) {
                        flag |= 1 << j;
                        break;
                    }
                }
            }
            if (flag == 1 || flag == 2 || flag == 4) {
                res.push_back(word);
            }
        }

        return res;
    }
};