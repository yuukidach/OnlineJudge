class Solution {
public:
    bool isEnough(vector<int> &weights, int D, int cap) {
        int cnt = 0;
        int sum = 0;
        for (auto &weight : weights) {
            sum += weight;
            if (sum > cap) {
                sum = weight;
                cnt++;
            }
        }
        cnt++;
        return cnt <= D;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int l, r = 25000010;
        l = *max_element(weights.begin(), weights.end());

        while (l < r) {
            int m = (l + r) >> 1;
            if (!isEnough(weights, D, m)) l = m + 1;
            else r = m;
        }

        return r;
    }
};