class UnionFind {
public:
    vector<int> parent;

    UnionFind(int _n) {
        parent.resize(_n);
        for (int i = 0; i < _n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        parent[ri] = rj;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if (len < n-1) return -1;
        UnionFind uf(n);
        for (const auto &connection : connections) {
            if (uf.find(connection[0]) == uf.find(connection[1])) continue;
            uf.unite(connection[0], connection[1]);
            n--;
        }

        return n-1;
    }
};