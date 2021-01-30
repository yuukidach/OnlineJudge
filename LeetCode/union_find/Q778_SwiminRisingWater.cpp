class UnionFind {
public:
    vector<int> pre;

    UnionFind(int _n) {
        pre.resize(_n);
        for (int i = 0; i < _n; ++i) pre[i] = i;
    }

    int find(int i) {
        while (i != pre[i]) {
            pre[i] = pre[pre[i]];
            i = pre[i];
        } 
        return i;
    }

    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        pre[ri] = rj;
    }

    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i) edges.emplace_back(max(grid[i][j], grid[i-1][j]), i*N+j, (i-1)*N+j);
                if (j) edges.emplace_back(max(grid[i][j], grid[i][j-1]), i*N+j, i*N+j-1);
            }
        }

        sort(edges.begin(), edges.end(), [](const auto &v1, const auto &v2){
            auto [x1, x2, x3] = v1;
            auto [y1, y2, y3] = v2;
            return x1 < y1;
        });

        int res;
        UnionFind uf(N*N);
        for (auto const & edge : edges) {
            if (uf.isConnected(0, N*N-1)) break;
            auto [d, x, y] = edge;
            if (uf.isConnected(x, y)) continue;
            uf.unite(x, y);
            res = d;
        }

        return res;
    }
};