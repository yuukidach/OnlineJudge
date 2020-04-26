class Solution {
public:
//     int dfs(vector<int>& card, int k, int l, int r) {
//         if (k == 0) return 0;
//         if (l == r) return card[l];
        
//         int res = 0;
        
//         res = dfs(card, k-1, l+1, r) + card[l];
//         res = max(res, dfs(card, k-1, l, r-1) + card[r]);
        
//         return res;
//     }
    
    int maxScore(vector<int>& cardPoints, int k) {
        // int res = dfs(cardPoints, k, 0 , cardPoints.size()-1);
        // return res;
        
        int len = cardPoints.size();
        int lk = len - k;
        
        int sum = 0;
        int small = 0;
        int tmp = 0;
        for(int i = 0; i < len; ++i) {
            sum += cardPoints[i];
        }
        for(int i = 0; i < lk; ++i) {
            tmp += cardPoints[i];
        }
        small = tmp;
        for(int i = lk; i < len; ++i) {
            tmp = tmp + cardPoints[i] - cardPoints[i-lk];
            small = min(tmp, small);
        }
        
        return sum - small;
    }
};