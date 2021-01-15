class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        for (auto edge : edges) {
            m[edge[0]].emplace_back(edge[1]);
            m[edge[1]].emplace_back(edge[0]);
        }
        int len = m.size() + 1;
        vector<int> ind(len, 0);
        vector<int> mark(len, 0);

        for (auto x : m) {
            ind[x.first] = x.second.size();
        }

        queue<int> q;
        for (int i = 0; i < len; ++i) {
            if (ind[i] == 1) {
                q.push(i);
                mark[i] = 1;
            }
        }

        int node = 1;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (auto nxt : m[node]) {
                ind[nxt]--;
                if (ind[nxt] == 1 && mark[nxt] == 0) {
                    q.push(nxt);
                    mark[nxt] = 1;
                }
            }
        }

        for (int i = edges.size()-1; i >= 0; --i) {
            int a = edges[i][0], b = edges[i][1];
            if (!mark[a] && !mark[b]) {
                return edges[i];
            }
        }

        vector<int> res;
        return res;
    }
};