class UnionFind {
public:
    vector<int> parent;
    int n;
    int cnt;

    UnionFind(int _n) {
        n = _n;
        cnt = _n;
        parent.resize(_n);
        for (int i = 0; i < _n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        parent[ri] = parent[rj];
        cnt--;
    }

    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int len = edges.size();
        for (int i = 0; i < len; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int> a, vector<int> b){
            return a[2] < b[2];
        });

        UnionFind uf(n);
        int std_val = 0;
        for (int i = 0; i < len; ++i) {
            int v = edges[i][0], u = edges[i][1];
            if (!uf.isConnected(v, u)) {
                uf.unite(v, u);
                std_val += edges[i][2];
            }
        }

        vector<vector<int>> res(2);
        for (int i = 0; i < len; ++i) {
            UnionFind test_uf(n);
            int val = 0;
            for (int j = 0; j < len; ++j) {
                if (i == j) continue;
                int v = edges[j][0], u = edges[j][1];
                if (!test_uf.isConnected(u, v)) {
                    test_uf.unite(v, u);
                    val += edges[j][2];
                }
            }
            if ((val > std_val && test_uf.cnt == 1) || test_uf.cnt != 1) {
                res[0].push_back(edges[i][3]);
                continue;
            }

            test_uf = UnionFind(n);
            test_uf.unite(edges[i][0], edges[i][1]);
            val = edges[i][2];
            for (int j = 0; j < len; ++j) {
                if (i == j) continue;
                int v = edges[j][0], u = edges[j][1];
                if (!test_uf.isConnected(u, v)) {
                    test_uf.unite(v, u);
                    val += edges[j][2];
                }
            }
            if (val == std_val) res[1].push_back(edges[i][3]);
        }

        return res;
    }
};