class Solution {
public:
    int dp[366];

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(int)*366);

        dp[0] = 0;
        int j = 0;
        int n = days[days.size()-1];
        for (int i = 1; i <= n; ++i) {
            if (i != days[j]) {
                dp[i] = dp[i-1];
                continue;
            }

            dp[i] = dp[i-1] + costs[0];
            dp[i] = min(dp[max(i-7, 0)] + costs[1], dp[i]);
            dp[i] = min(dp[max(i-30, 0)] + costs[2], dp[i]);
            j++;
        }

        return dp[n];
    }
};