class UnionFind {
public:
    vector<int> pre;
    int cnt;

    UnionFind(int _n) {
        pre.resize(_n);
        for (int i = 0; i < _n; ++i) pre[i] = i;
        cnt = _n;
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
        if (ri == rj) return;
        pre[ri] = rj;
        cnt--;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].size();
        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < len; ++k) {
                    if (strs[i][k] != strs[j][k]) diff++;
                    if (diff > 2) break;
                }
                if (diff <= 2) uf.unite(i, j);
            }
        }

        return uf.cnt;
    }
};