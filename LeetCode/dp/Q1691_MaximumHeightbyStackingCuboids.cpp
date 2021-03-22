class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &cub : cuboids) {
            sort(cub.begin(), cub.end(), greater<>());
        }

        sort(cuboids.begin(), cuboids.end(), [](auto &a, auto &b) {
            return make_tuple(a[0], a[1], a[2]) > make_tuple(b[0], b[1], b[2]);
        });

        int n = cuboids.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][0];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[i][0] <= cuboids[j][0] && \
                    cuboids[i][1] <= cuboids[j][1] && \
                    cuboids[i][2] <= cuboids[j][2])
                    dp[i] = max(dp[i], dp[j] + cuboids[i][0]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};