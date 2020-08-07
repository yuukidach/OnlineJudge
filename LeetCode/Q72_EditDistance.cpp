class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int dis[1000][1000];

        for (int i = 0; i <= len1; ++i) dis[i][0] = i;
        for (int i = 0; i <= len2; ++i) dis[0][i] = i;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int step = word1[i-1] == word2[j-1] ? 0 : 1;
                int tmp_dis = min(dis[i-1][j] + 1, dis[i][j-1] + 1);
                dis[i][j] = min(tmp_dis, dis[i-1][j-1] + step);
            }
        }

        return dis[len1][len2];
    }
};