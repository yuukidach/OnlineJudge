class Solution {
public:
    int find(vector<int> &parent, int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    void Union(vector<int> &parent, int i, int j) {
        int p1 = find(parent, i);
        int p2 = find(parent, j);
        if (p1 != p2) {
            parent[p2] = p1;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto pair : pairs) {
            Union(parent, pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < s.length(); ++i) {
            m[find(parent, i)].emplace_back(s[i]);
        }

        for (auto &[key, val] : m) {
            sort(val.begin(), val.end(), greater<int>());
        }
        for (int i = 0; i < n; ++i) {
            int p = find(parent, i);
            s[i] = m[p].back();
            m[p].pop_back();
        }

        return s;
    }
};