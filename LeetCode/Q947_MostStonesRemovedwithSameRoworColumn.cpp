class Solution {
public:
    int findParent(vector<int> &pre, int i) {
        while (i != pre[i]) {
            pre[i] = pre[pre[i]];
            i = pre[i];
        }
        return i;
    }

    void Union(vector<int> &pre, int i, int j) {
        int ri = findParent(pre, i);
        int rj = findParent(pre, j);
        if (ri != rj) pre[ri] = pre[rj];
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int base = 10000+1;
        vector<int> pre(2*base, 0);
        for (auto stone : stones) {
            pre[stone[0]] = stone[0];
            pre[stone[1] + base] = stone[1] + base;
        }

        for (auto stone : stones) {
            int x = stone[0];
            int y = stone[1] + base;
            if (findParent(pre, x) != findParent(pre, y)) Union(pre, x, y);
        }

        set<int> s;
        for (auto stone : stones) {
            s.emplace(findParent(pre, stone[0]));
        }

        return n - s.size();
    }
};