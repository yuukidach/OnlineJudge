class UnionFind {
public:
    int cnt;
    vector<int> pre;

    UnionFind(int _n) {
        cnt = _n;
        pre.resize(_n);
        for (int i = 0; i < _n; ++i) pre[i] = i;
    }

    int find(int i) {
        while (pre[i] != i) {
            pre[i] = pre[pre[i]];
            i = pre[i];
        }
        return i;
    }

    bool isConnected(int i, int j){
        return find(i) == find(j);
    }

    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri != rj) {
            pre[ri] = rj;
            cnt--;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(4*n*n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ord = i * n + j << 2;
                if (j > 0) uf.unite(ord-3, ord+3);
                if (i > 0) uf.unite(ord, ((i-1)*n+j<<2)+2);
                if (grid[i][j] == '/') {
                    uf.unite(ord, ord+3);
                    uf.unite(ord+1, ord+2);
                } else if (grid[i][j] == '\\') {
                    uf.unite(ord, ord+1);
                    uf.unite(ord+2, ord+3);
                } else {
                    uf.unite(ord, ord+1);
                    uf.unite(ord, ord+2);
                    uf.unite(ord, ord+3);
                }
            }
        }

        return uf.cnt;
    }
};