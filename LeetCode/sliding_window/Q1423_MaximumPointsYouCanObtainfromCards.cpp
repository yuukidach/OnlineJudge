class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int l = 0, r = len-k;
        int sum = 0;
        for (int i = 0; i < r; ++i) sum += cardPoints[i];

        int min_sum = sum;
        while (r < len) {
            sum -= cardPoints[l];
            sum += cardPoints[r];
            min_sum = min(min_sum, sum);
            l++, r++;
        }

        for (int i = 0; i < len; ++i) min_sum -= cardPoints[i];
        return -min_sum;
    }
};