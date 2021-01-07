class Solution {
public:
    int findRoot(vector<int> &mark, int i) {
        while(mark[i] != i) {
            i = mark[i];
        }
        return i;
    }

    void Union(vector<int> &mark, int i, int j) {
        int flag = -1, p = j;
        int rooti = findRoot(mark, i);
        int rootj = findRoot(mark, j);

        mark[rootj] = mark[rooti];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<int> mark(len, 0);
        for (int i = 0; i < len; ++i) mark[i] = i;

        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; j++) {
                if (isConnected[i][j] == 0) continue;
                Union(mark, i, j);
            }
        }

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (mark[i] == i) cnt++;
        }

        return cnt;
    }
};