class Solution {
public:
    int getCp(int i) {
        if (i % 2 == 0) 
            return i + 1;
        return i-1;
    }

    int minSwapsCouples(vector<int>& row) {
        int len = row.size(), cnt = 0;
        vector<int> pos(len, 0);

        for (int i = 0; i < len; ++i) {
            pos[row[i]] = i;
        }

        for (int i = 0; i < len; i = i + 2) {
            int nxt = row[i + 1];
            int j = getCp(row[i]);
            if (j == nxt) continue;
            swap(row[pos[j]], row[i + 1]);
            swap(pos[j], pos[nxt]);
            cnt++;
        }
        return cnt;
    }
};