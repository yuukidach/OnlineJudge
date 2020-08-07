class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int len = satisfaction.size();
        int idx = 0;
        int sum = 0;

        sort(satisfaction.begin(), satisfaction.end());
        for(idx = 0; idx < len; ++idx) {
            if (satisfaction[idx] >= 0) break;
        }

        int pos_sum = 0;
        int l = 0;
        for (int i = idx; i < len; ++i) pos_sum += satisfaction[i];
        for (int i = idx - 1; i >= 0; --i) {
            if (-satisfaction[i] < pos_sum) pos_sum += satisfaction[i];
            else {
                l = i + 1;
                break;
            }
        }
     
        for (int i = l; i < len; ++i) {
            sum += satisfaction[i] * (i-l+1);
        }

        return sum;
    }
};