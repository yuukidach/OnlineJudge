class Solution {
public:
    unordered_map<int, int> m;

    void buildMap(string word) {
        int key = 0;
        for (auto &ch : word) {
            key |= 1 << ch - 'a';
        }
        if (m.count(key)) m[key]++;
        else m[key] = 1;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int len = puzzles.size();
        for (auto &word : words) buildMap(word);
        vector<int> res(len);

        for (int i = 0; i < len; ++i) {
            int key = 0, start = 1 << puzzles[i][0] - 'a';
            for (auto &ch : puzzles[i]) {
                key |= 1 << ch - 'a';
            }
            for (int j = key; j; j = (j-1) & key) {
                if (j & start) res[i] += m[j];
            }
        }

        return res;
    }
};