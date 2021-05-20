class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string &word: words) m[word]++;

        vector<string> res, v;
        for (auto &[key, val] : m) {
            v.emplace_back(key);
        }
        sort(v.begin(), v.end(), [&m](string &a, string &b) {
            return m[a] == m[b] ? a < b : m[a] > m[b];
        });

        for (int i = 0; i < k; ++i) {
            res.emplace_back(v[i]);
        }

        return res;
    }
};

